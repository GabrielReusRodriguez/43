/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:49:32 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 22:21:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

bool	fd_copy(int oldfd, int *newfd)
{
	if (oldfd < 0)
	{
		ft_err_error("Copying from < 0 fd.");
		return (false);
	}
	*newfd = dup(oldfd);
	if (*newfd < 0)
	{
		ft_err_errno(NULL);
		return (false);
	}
	return(true);
}

bool	fd_replace(int oldfd, int newfd)
{
	int	res_dup;

	if (oldfd < 0)
	{
		ft_err_error("Copying from < 0 fd.");
		return (false);
	}
	if (newfd < 0)
	{
		ft_err_error("Copying to < 0 fd.");
		return (false);
	}
	res_dup = dup2(oldfd, newfd);
	if (res_dup < 0)
	{
		ft_err_errno(NULL);
		return (false);
	}
	return(true);
	
}

bool	fd_close(int fd)
{
	if (close(fd) < 0)
	{
		ft_err_errno(NULL);
		return (false);
	}
	return (true);
}
