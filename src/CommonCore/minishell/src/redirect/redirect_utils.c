/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:45:31 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 13:19:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "redirection.h"
#include "libft.h"

void	redirect_init(t_redirection *redir)
{
	redir->file = NULL;
	redir->lim_here_doc = NULL;
	redir->here_string = NULL;
	redir->type = REDIRECT_NONE;
}

bool	redirect_new(t_redirection	**redirect)
{
	*redirect = (t_redirection *)malloc(sizeof(t_redirection));
	if (*redirect == NULL)
		return (ft_err_errno(NULL), false);
	redirect_init(*redirect);
	return (true);
}

void	redirect_destroy(t_redirection *redir)
{
	free (redir->file);
	redir->file = NULL;
	free (redir->here_string);
	redir->here_string = NULL;
	free (redir->lim_here_doc);
	redir->lim_here_doc = NULL;
}

void	redirect_clear_list_node(void *arg)
{
	t_redirection *redir;

	redir = (t_redirection *)arg;
	free (redir->file);
	redir->file = NULL;
	free (redir->here_string);
	redir->here_string = NULL;
	free (redir->lim_here_doc);
	redir->lim_here_doc = NULL;
	free(arg);
}