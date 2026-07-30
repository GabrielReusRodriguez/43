/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:53:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/03 22:02:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> 

#include "ft_error.h"
#include "ft_fd.h"
//#include "ft_utils.h"
#include "ft_files.h"

bool	ft_fd_pipe_close(int fd[2], int which_fd)
{
	if (which_fd == PIPE_READ_FD && close(fd[PIPE_READ_FD]) == -1)
	{
		ft_error_print_errno(NULL);
		return (false);
	}
	if (which_fd == PIPE_WRITE_FD && close(fd[PIPE_WRITE_FD]) == -1)
	{
		ft_error_print_errno(NULL);
		return (false);
	}
	if (which_fd == PIPE_ALL_FD)
	{
		if (close(fd[PIPE_READ_FD]) == -1 || close(fd[PIPE_WRITE_FD]) == -1)
		{
			ft_error_print_errno(NULL);
			return (false);
		}
	}
	return (true);
}

void	ft_fd_check(int fdin, int fdout)
{
	if (fdin < 0 || fdout < 0)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
	}
}

void	ft_fd_dups(int fdin, int fdout)
{
	if (dup2(fdin, STDIN_FILENO) == -1 || dup2(fdout, STDOUT_FILENO) == -1)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
	}
}
