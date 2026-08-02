/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds_outputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:28:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/29 22:52:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "minishell.h"
#include "cmd.h"
#include "redirection.h"
#include "fd.h"
#include "path.h"
#include "libft.h"


//bool	path_check_mask(const char *path, int mask, bool verbose)
static bool	treat_out_add_red(t_redirection *redir, t_cmd *cmd)
{
	t_path_types	type;
	int				fd;
	
	if (path_check_mask(redir->file, F_OK, false))
	{
		if (!path_check_mask(redir->file, F_OK | W_OK, true))
			return (false);
		if (!path_get_type(redir->file, &type, true))
			return (false);
		if (type != PATH_TYPE_FILE)
			return (ft_err_error("Is a directory"), true);
	}
	fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, \
				S_IRUSR | S_IWUSR | \
				S_IRGRP | S_IWGRP | \
				S_IROTH
			);
	if (fd < 0)
		return (ft_err_errno(NULL), false);
	cmd->fd_out = fd;
	return (true);
}

static bool	treat_out_app_red(t_redirection *redir, t_cmd *cmd)
{
	t_path_types	type;
	int				fd;
	
	if (path_check_mask(redir->file, F_OK, false))
	{
		if (!path_check_mask(redir->file, F_OK | W_OK, true))
			return (false);
	}
	if (!path_get_type(redir->file, &type, true))
		return (false);
	if (type != PATH_TYPE_FILE)
		return (ft_err_error("Is a directory"), true);
	fd = open(redir->file, O_CREAT | O_APPEND | O_WRONLY, \
				S_IRUSR | S_IWUSR | \
				S_IRGRP | S_IWGRP | \
				S_IROTH);
	if (fd < 0)
		return (ft_err_errno(NULL), false);
	cmd->fd_out = fd;
	return (true);
}


static bool	treat_out_redirection(t_redirection *redir, t_cmd *cmd)
{
	if (redir->type == REDIRECT_OUT_ADD)
		return (treat_out_add_red(redir, cmd));
	if (redir->type == REDIRECT_OUT_APPEND)
		return (treat_out_app_red(redir, cmd));
	return (true);
}

// Cada nodo de la lista de redirecciones es del tipo : 	t_redirection	*redirection;
bool	cmd_open_redir_outputs(t_cmd *cmd)
{
	t_list			*node;
	t_redirection	*redir;

	node = cmd->output_redirections;
	while(node != NULL)
	{
		if (cmd->fd_out != FD_NONE)
		{
			if(!fd_close(cmd->fd_out))
				return (false);
		}
		redir = (t_redirection *)node->content;
		if (!treat_out_redirection(redir, cmd))
			return (false);
		node = node->next;
	}
	return (true);
}
