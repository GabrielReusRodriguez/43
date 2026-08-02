/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:59:34 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 22:53:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"
#include "redirection.h"
#include "tokenizer/tokenizer.h"

#include <stdio.h>

static	bool	redirect_parse_input(t_list **node, t_redirection **redir)
{
	t_token	*token;

	if (!redirect_new(redir))
		return (false);
	token = (t_token *)(*node)->content;
	if (ft_strcmp("<", token->text) == 0)
	{
		(*redir)->type = REDIRECT_IN_FILE;
		(*node) = (*node)->next;
		token = (t_token *)(*node)->content;
		(*redir)->file = ft_strdup(token->text);
		if ((*redir)->file == NULL)
			return (free (*redir),false);
		(*node) = (*node)->next;
	}
	if (ft_strcmp("<<", token->text) == 0)
	{
		(*redir)->type = REDIRECT_IN_HEREDOC;
		(*node) = (*node)->next;
		token = (t_token *)(*node)->content;
		(*redir)->lim_here_doc = ft_strdup(token->text);
		if ((*redir)->lim_here_doc == NULL)
			return (free (*redir),false);
		(*node) = (*node)->next;
	}
	if (ft_strcmp("<<<", token->text) == 0)
	{
		(*redir)->type = REDIRECT_IN_HERESTRING;
		(*node) = (*node)->next;
		token = (t_token *)(*node)->content;
		(*redir)->here_string = ft_strdup(token->text);
		if ((*redir)->here_string == NULL)
			return (free (*redir),false);
		(*node) = (*node)->next;
	}

	return (true);
}

static	bool	redirect_parse_output(t_list **node, t_redirection **redir)
{
	t_token	*token;

	if (!redirect_new(redir))
		return (false);
	token = (t_token *)(*node)->content;
	if (ft_strcmp(">", token->text) == 0)
	{
		(*redir)->type = REDIRECT_OUT_ADD;
		(*node) = (*node)->next;
		token = (t_token *)(*node)->content;
		(*redir)->file = ft_strdup(token->text);
		if ((*redir)->file == NULL)
			return (free (*redir),false);
		(*node) = (*node)->next;
	}
	if (ft_strcmp(">>", token->text) == 0)
	{
		(*redir)->type = REDIRECT_OUT_APPEND;
		(*node) = (*node)->next;
		token = (t_token *)(*node)->content;
		(*redir)->file = ft_strdup(token->text);
		if ((*redir)->file == NULL)
			return (free (*redir),false);
		(*node) = (*node)->next;
	}
	return (true);	
}

bool	redirect_parse(t_list **node, t_redirection **redir)
{
	t_token *token;
	
	token = (t_token *)(*node)->content;
	*redir = NULL;

	if (token->type != TOKEN_TYPE_REDIR)
		return (true);
	if (token->text[0] == '<')
		return (redirect_parse_input(node, redir));
	if (token->text[0] == '>')
		return (redirect_parse_output(node, redir));
	return (true);
}
