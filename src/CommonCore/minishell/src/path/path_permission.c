/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_permission.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:33:32 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/17 21:33:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "libft.h"
#include "minishell.h"

/*
int access(const char *pathname, int mode);
	-1 en caso de error , 0 si todo ok. (incluye errno.)
*/

bool	path_check_mask(const char *path, int mask, bool verbose)
{
	if (access(path, mask) < 0)
	{
		if (verbose)
			ft_err_errno(NULL);
		return (false);
	}
	return (true);
}

bool	path_can_exec(const char *path, bool verbose)
{
	return (path_check_mask(path, X_OK ,verbose));
}

bool	path_can_read(const char *path, bool verbose)
{
	return (path_check_mask(path, R_OK ,verbose));
}

bool	path_can_write(const char *path, bool verbose)
{
	return (path_check_mask(path, W_OK ,verbose));
}

bool	path_can_exists(const char *path, bool verbose)
{
	return (path_check_mask(path, F_OK ,verbose));
}
