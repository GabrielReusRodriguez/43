/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:39:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 18:51:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

#include "pipe.h"
#include "libft.h"
#include "fd.h"

t_pipe	pipe_new(void)
{
	t_pipe	my_pipe;

	my_pipe.read = FD_NONE;
	my_pipe.write = FD_NONE;
	return (my_pipe);	
}

bool	pipe_open(t_pipe *my_pipe)
{
	int	v_pipe[2];
	
	if (pipe(v_pipe) < 0)
	{
		my_pipe->read = FD_NONE;
		my_pipe->write = FD_NONE;
		ft_err_errno(NULL);
		return(false);
	}
	my_pipe->read = v_pipe[0];
	my_pipe->write = v_pipe[1]; 
	return (true);
}

bool	pipe_close(t_pipe *my_pipe)
{
	bool	close_read;
	bool	close_write;

	close_read = true;
	close_write = true;
	if (my_pipe->read != FD_NONE)
	{	
		if (close(my_pipe->read) < 0)
		{
			ft_err_errno(NULL);
			close_read = false;
		}
		my_pipe->read = FD_NONE;
	}
	if (my_pipe->write != FD_NONE)
	{	
		if (close(my_pipe->write) < 0)
		{
			ft_err_errno(NULL);
			close_write = false;
		}
		my_pipe->write = FD_NONE;
	}
	return (close_read && close_write);
}
