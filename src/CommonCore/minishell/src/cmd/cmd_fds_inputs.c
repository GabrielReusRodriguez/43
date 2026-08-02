/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:28:39 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 14:28:47 by gabriel          ###   ########.fr       */
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
#include "ft_get_next_line.h"

static bool	treat_file_redir(t_cmd *cmd, t_redirection *redir)
{
	t_path_types	type;
	int				fd;

	if (!path_check_mask(redir->file, F_OK | R_OK, true))
		return (false);
	if (!path_get_type(redir->file, &type, true))
		return (false);
	if (type != PATH_TYPE_FILE)
		return (ft_err_error("Is a directory"), true);
	fd = open(redir->file, O_RDONLY);
	if (fd < 0)
		return (ft_err_errno(NULL), false);
	cmd->fd_in = fd;
	return (true);
}

static bool	treat_heredoc_redir(t_cmd *cmd, t_redirection *redir)
{
	int			fd;
	char		*line;
	char		*limitor;

	line = "";
	limitor = ft_strjoin(redir->lim_here_doc, "\n");
	if (limitor == NULL)
		return (ft_err_errno(NULL), false);
	//Al crearlo con O_TMP_FILE, cuando se haga el close del ultimo fd, se elimina el fichero.
	fd = open("/tmp/", __O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		free (limitor);
		return (ft_err_errno(NULL), false);
	}
	cmd->fd_in = fd;
	while (line != NULL)
	{
		ft_iputstr_fd("> ", STDOUT_FILENO);
		line = ft_get_next_line_many_fds(STDIN_FILENO);
		if (line == NULL || ft_strcmp(line, limitor) == 0)
		{
			free (line);
			break;
		}
		ft_iputstr_fd(line, fd);
		free (line);
	}
	free (limitor);
	//reseteamos el file descriptor a la posicion 0
	if (lseek(fd, 0, SEEK_SET) < 0)
	{
		fd_close(cmd->fd_in);
		cmd->fd_in = FD_NONE;
		return (ft_err_errno(NULL), false);
	}
	return (true);
}

static bool	treat_herestring_redir(t_cmd *cmd, t_redirection *redir)
{
	int	fd;	

	fd = open("/tmp/", __O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return (ft_err_errno(NULL), false);
	cmd->fd_in = fd;
	ft_putendl_fd(redir->here_string, fd);
	if (lseek(fd, 0, SEEK_SET) < 0)
	{
		fd_close(cmd->fd_in);
		cmd->fd_in = FD_NONE;
		return (ft_err_errno(NULL), false);
	}
	return (true);	
}

static bool	treat_in_redirection(t_cmd *cmd, t_redirection *redir)
{
	if (redir->type == REDIRECT_IN_FILE)
		return (treat_file_redir(cmd, redir));
	if (redir->type == REDIRECT_IN_HEREDOC)
		return (treat_heredoc_redir(cmd, redir));
	if (redir->type == REDIRECT_IN_HERESTRING)
		return(treat_herestring_redir(cmd, redir));
	return (true);
}

// Cada nodo de la lista de redirecciones es del tipo : 	t_redirection	*redirection;
bool	cmd_open_redir_inputs(t_cmd *cmd)
{
	t_list			*node;
	t_redirection	*redir;

	node = cmd->input_redirections;
	while(node != NULL)
	{
		if (cmd->fd_in != FD_NONE)
		{
			if(!fd_close(cmd->fd_in))
				return (false);
		}
		redir = (t_redirection *)node->content;
		if (!treat_in_redirection(cmd, redir))
			return (false);
		node = node->next;
	}
	return (true);
}