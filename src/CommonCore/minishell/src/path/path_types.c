/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:03:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/29 19:34:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "path.h"
#include "libft.h"


/*
 	switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
*/
bool	path_is_directory(const char *path, bool *is_dir, bool verbose)
{
	struct stat	statbuf;

	*is_dir = false;
	//Si no existe o no tienes permiso, te devolverá 0.
	if (stat(path, &statbuf) != 0)
	{
		if (verbose)
			ft_err_errno(NULL);
		return (false);
	}
	if (S_ISDIR(statbuf.st_mode) != 0)
		*is_dir = true;
	return (true);
}

bool	path_is_file(const char *path, bool *is_file, bool verbose)
{
	struct stat	statbuf;

	*is_file = false;
	//Si no existe o no tienes permiso, te devolverá 0.
	if (stat(path, &statbuf) != 0)
	{
		if (verbose)
			ft_err_errno(NULL);
		return (false);
	}
	if (S_ISREG(statbuf.st_mode) != 0)
		*is_file = true;
	return (true);
}


bool	path_get_type(const char *path, t_path_types *type, bool verbose)
{
	struct stat	statbuf;

	*type = PATH_TYPE_UNKONWN;
	//Si no existe o no tienes permiso, te devolverá 0.
	if (stat(path, &statbuf) != 0)
	{
		*type = PATH_TYPE_NOT_EXISTS;
		if (verbose)
			ft_err_errno(NULL);
		return (false);
	}
	if (S_ISREG(statbuf.st_mode) != 0)
	{
		*type = PATH_TYPE_FILE;
		return (true);
	}
	if (S_ISDIR(statbuf.st_mode) != 0)
	{
		*type = PATH_TYPE_FOLDER;
		return (true);
	}
	return (true);
}