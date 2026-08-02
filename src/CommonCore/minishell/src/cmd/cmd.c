/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:51:09 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 13:05:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cmd.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "libft.h"
#include "redirection.h"

#include <stdio.h>
//	bool	redirect_parse(t_list **node, t_redirection **redir);
static bool	cmd_add_redirection(t_list **node, t_cmd *cmd)
{
	t_redirection	*redirection;
	t_list			*redir_node;

	if (!redirect_parse(node, &redirection))
		return (false);
	redir_node = ft_lstnew(redirection);
	if (redir_node == NULL)
	{
		ft_err_errno(NULL);
		redirect_destroy(redirection);
		return (free (redirection),false);
	}
	if (redirection->type == REDIRECT_IN_FILE || \
			redirection->type == REDIRECT_IN_HEREDOC || \
			redirection->type == REDIRECT_IN_HERESTRING)
		ft_lstadd_back(&cmd->input_redirections, redir_node);
	if (redirection->type == REDIRECT_OUT_ADD || \
			redirection->type == REDIRECT_OUT_APPEND)
		ft_lstadd_back(&cmd->output_redirections, redir_node);
	return (true);
}

static bool	cmd_add_word(t_list **node, t_cmd *cmd)
{
	t_token *token;
	t_list	*param_node;
	char	*param;

	token = (t_token*)(*node)->content;
	if (cmd->executable == NULL)
	{
		cmd->executable = ft_strdup(token->text);
		if (cmd->executable == NULL)
			return(ft_err_errno(NULL), false);
	}
	else
	{
		param = ft_strdup(token->text);
		if (param == NULL)
			return(ft_err_errno(NULL), false);
		param_node = ft_lstnew(param);
		if (param_node == NULL)
		{
			ft_err_errno(NULL);
			return (free(param), false);
		}
		ft_lstadd_back(&cmd->args, param_node);
	}
	*node = (*node)->next;
	return (true);
}

static void	cmd_get_type(t_list *node, t_cmd *cmd)
{
	t_token	*token;
	
	if (node == NULL)
		(cmd)->type = CMD_TYPE_SINGLE;
	else
	{
		token = (t_token *)node->content;
		if (token->type == TOKEN_TYPE_PIPE)
			cmd->type = CMD_TYPE_PIPE;
		else
			cmd->type = CMD_TYPE_SINGLE;
	}
}

bool	cmd_parse_tokens(t_list *init, t_list *final, t_cmd **cmd)
{
	t_token	*token;		
	t_list	*init_node;
	
	
	*cmd = (t_cmd*)malloc(sizeof(t_cmd));
	if (*cmd == NULL)
		return (ft_err_errno(NULL), false);
	cmd_init(*cmd);
	init_node = init;
	while (init_node != final)
	{
		token = (t_token *)init_node->content;
//		printf("token cmd type %d  text _%s_ \n", token->type, token->text);
		if (token->type == TOKEN_TYPE_REDIR)
		{
			if (!cmd_add_redirection(&init_node, *cmd))
			{
				cmd_destroy(*cmd);
				return (free(*cmd), false);
			}
			
			continue;
		}
		if (token->type == TOKEN_TYPE_WORD)
		{
//			printf("Entra word\n");
			if (!cmd_add_word(&init_node,*cmd))
			{
				cmd_destroy(*cmd);
				return (free(*cmd), false);
			}
			continue;
		}
		init_node = init_node->next;
	}
	cmd_get_type(final, *cmd);
//	cmd_debug(*cmd);
	return (true);
}