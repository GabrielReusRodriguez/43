/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:05:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 13:03:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "libft.h"

#include <stdio.h>

/*
static void debug_tokens(t_list *list)
{
	t_list *node;
	t_token *token;

	node = list;
	while(node != NULL)
	{
		token = (t_token *)node->content;
		printf("TOKEN******************\n");
		printf("\ttext: _%s_\n",token->text);
		printf("\ttype: _%d_\n", token->type);
		printf("END TOKEN**************\n");

		node = node->next;
	}
}
*/

static void determine_token_word_type(t_token_type *type, char actual_char)
{
	if (*type != TOKEN_TYPE_DQUOTE && *type != TOKEN_TYPE_SQUOTE)
	{
		if (actual_char == '\"')
			*type = TOKEN_TYPE_DQUOTE;
		if (actual_char == '\'')
			*type = TOKEN_TYPE_SQUOTE;
	}
}

static bool tokenizer_get_end_of_next_token(const char *cmd, \
					size_t *final, t_token_type *type)
{
	char	separator;
	
	separator = ' ';
	*type = TOKEN_TYPE_WORD;
	while (cmd[*final] != '\0')
	{
		if (separator == ' ')
		{
			if (cmd[*final] == '\"' || cmd[*final] == '\'')
			{
				determine_token_word_type(type, cmd[*final]);
				separator = cmd[*final];
				(*final)++;
				continue;
			}
			if (cmd[*final] == ' ' || \
					ft_strchr(TOKENIZER_COMMAND_SEPARATOR, cmd[*final]) != NULL ||
					ft_strchr(TOKENIZER_REDIRECTION_CHAR, cmd[*final]) != NULL
					)
				return (true);
		}
		else
			if (cmd[*final] == separator)
				separator = ' ';
		(*final)++;
	}
	if (separator == '\'' || separator == '\"')
		return (ft_err_error("Detected unclosed quoted cmd"), false);
	return (true);
}

static bool	tokenizer_get_end_of_redir(const char *cmd, size_t *final)
{
	if (cmd[*final] == '>')
	{
		(*final)++;
		if (cmd[*final] == '>')
			(*final)++;
		return (true);
	}
	if (cmd[*final] == '<')
	{
		(*final)++;
		if (cmd[*final] == '<')
			(*final)++;
		if (cmd[*final] == '<')
			(*final)++;
		if (cmd[*final] == '<' || cmd[*final] == '>')
			return (ft_err_error("Syntax error"), false);
	}
	return (true);
}

static	bool	tokenizer_get_next_token(const char *cmd, size_t init, \
					size_t *final, t_token **token)
{
	t_token_type	type;
	bool			result;
	
	if (ft_strchr(TOKENIZER_COMMAND_SEPARATOR, cmd[init]) != NULL)
	{
		(*final)++;
		return (tokenizer_extract_token(cmd, init, *final, token));
	}
	if (ft_strchr(TOKENIZER_REDIRECTION_CHAR, cmd[init]) != NULL)
	{
		if (!tokenizer_get_end_of_redir(cmd, final))
			return (false);
		return (tokenizer_extract_token(cmd, init, *final, token));
	}
	if (!tokenizer_get_end_of_next_token(cmd, final, &type))
		return (false);
	if (init != *final)
	{
		result = tokenizer_extract_token(cmd, init, *final, token);
		if (result)
			(*token)->type = type; 
		return (result);
	}
	return (true);
}

bool	tokenizer_get_tokens(const char *cmd, t_list **token_list)
{
	size_t	i;
	size_t	last_read_char;
	t_token	*token;
	t_list	*node;

	i = 0;
	last_read_char = 0;
	while (cmd[i] != '\0')
	{
		while(cmd[i] == ' ' && cmd[i] != '\0')
			i++;
		if (cmd[i] == '\0')
			break;
		last_read_char = i;
		if (!tokenizer_get_next_token(cmd, i, &last_read_char, &token))
			return (ft_lstclear(token_list, tokenizer_clear_list_node), false);
		if (!token_new_list_node(&node, token))
		{	
			token_destroy(token);
			free (token);
			ft_lstclear(token_list, tokenizer_clear_list_node);
			return (false);
		}
		ft_lstadd_back(token_list, node);
		i = last_read_char;
	}
//	debug_tokens(*token_list);
	return (true);
}
