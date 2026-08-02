/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:33:46 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 14:25:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "expansor.h"
#include "env/environment.h"
#include "utils/string.h"

#include <stdio.h>
#include <stdlib.h>

#include "tokenizer/tokenizer.h"

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
static bool	expansor_expand_node(t_list *node, t_list **new_nodes, t_environment env)
{
	t_token			*token;
	char			*new_cmd;
	char			*unquoted;
	t_token_type	type;

	unquoted = NULL;
	new_cmd = NULL;
	token = (t_token *)node->content;
	if (!expansor_expand_string(token->text,env, &new_cmd))
		return (false);
	//Added unquote .
	if (!utils_string_unquote(new_cmd, &unquoted))
		return (false);
	free (new_cmd);
	//End Added unquote.
//	printf("Unquoted: _%s_\n", unquoted);
	//bool	token_new(t_token **token, char *_text, t_token_type _type)
	type = token->type;
	if (type == TOKEN_TYPE_DQUOTE || type == TOKEN_TYPE_SQUOTE)
		type = TOKEN_TYPE_WORD;
	if (!token_new (&token, unquoted, type))
	{
		free(unquoted);
		return (ft_err_errno(NULL), false);
	}
	*new_nodes = ft_lstnew(token);
	//if (!tokenizer_get_tokens(unquoted, new_nodes))
	//	return (free (unquoted), false);
	//free (unquoted);
	return (true);
}

bool	expansor_expand(t_list **token_list, t_environment env)
{
	t_list	*node;
	t_list	*new_list;
	t_list	*new_nodes;
	
	node = *token_list;
	new_list = NULL;
	while (node != NULL)
	{
		new_nodes = NULL;
		if (!expansor_expand_node(node, &new_nodes, env))
			return (false);
		ft_lstadd_back(&new_list,new_nodes);
		node = node->next;
	}
	ft_lstclear(token_list, tokenizer_clear_list_node);
	*token_list = new_list;
//	debug_tokens(*token_list);
	return (true);
}
