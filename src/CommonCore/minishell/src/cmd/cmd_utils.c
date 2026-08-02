/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:51:09 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 23:45:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cmd.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "fd.h"
#include "redirection.h"

#include <stdio.h>

t_cmd	cmd_new(void)
{
	t_cmd	cmd;
	
	cmd_init(&cmd);
	return (cmd);
}

void	cmd_init(t_cmd *cmd)
{
	cmd->pid = -1;
	cmd->return_value = -1;
	cmd->input_redirections = NULL;
	cmd->executable = NULL;
	cmd->args = NULL;
	cmd->output_redirections = NULL;	
	cmd->fd_in = FD_NONE;
	cmd->fd_out = FD_NONE;
}

void	cmd_destroy(t_cmd *cmd)
{
	if (cmd->input_redirections != NULL)
		ft_lstclear(&cmd->input_redirections, tokenizer_clear_list_node);
	if (cmd->executable != NULL)
//		token_destroy(cmd->executable);
		free (cmd->executable);
	if (cmd->args != NULL)
//		ft_lstclear(&cmd->args, tokenizer_clear_list_node);
		ft_lstclear(&cmd->args, free);
	if (cmd->output_redirections != NULL)
		ft_lstclear(&cmd->output_redirections, tokenizer_clear_list_node);
}

void	cmd_clear_list_node(void *arg)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)arg;
	ft_lstclear(&cmd->input_redirections, redirect_clear_list_node);
	ft_lstclear(&cmd->args, free);
	free (cmd->executable);
	cmd->executable = NULL;
	ft_lstclear(&cmd->output_redirections, redirect_clear_list_node);	
	//Borramos el propio puntero al content ya que ft_lstclear no lo hará.
	free (arg);
}


void	cmd_debug(t_cmd *debug)
{
	t_list	*node;
	t_redirection *redir;

	printf("DEBUG CMD***********************************\n");
	node = debug->input_redirections;
	if (node == NULL)
		printf("\tNO input redirections.\n");
	else
	{
		printf("\tInputs redirections: \n");
		while (node != NULL)
		{
			redir = (t_redirection *)node->content;
			if (redir->type == REDIRECT_IN_FILE)
				printf("\t\tINPUT FILE redirection to _%s_\n", redir->file);
			if (redir->type == REDIRECT_IN_HEREDOC)
				printf("\t\tINPUT HERE_DOC redirection lim _%s_\n", redir->lim_here_doc);
			node = node->next;
		}
	}
	printf("\texecutable: _%s_\n",debug->executable);
	node = debug->args;
	if (node == NULL)
		printf("\tNO args\n");
	else
	{
		printf("\tARGS: \n");
		while (node != NULL)
		{
			printf("\t\t_%s_\n", (char *)node->content);
			node = node->next;
		}
	}
	node = debug->output_redirections;
	if (node == NULL)
		printf("\tNO output redirections.\n");
	else
	{
		printf("\tOutputs redirections: \n");
		while (node != NULL)
		{
			redir = (t_redirection *)node->content;
			if (redir->type == REDIRECT_OUT_ADD)
				printf("\t\tOUTPUT ADD redirection to _%s_\n", redir->file);
			if (redir->type == REDIRECT_OUT_APPEND)
				printf("\t\tOUTPUT APPEND redirection to _%s_\n", redir->file);
			node = node->next;
		}
	}
	printf("\t Type: %d\n", debug->type);
	printf("END DEBUG CMD*******************************\n");
}