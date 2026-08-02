/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:31:42 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/29 19:14:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "minishell.h"
# include "cmd.h"

typedef enum e_path_types
{
	PATH_TYPE_UNKONWN,
	PATH_TYPE_FILE,
	PATH_TYPE_FOLDER,
	PATH_TYPE_NOT_EXISTS

} t_path_types;

//path/path_permission.c
bool	path_can_exec(const char *path,  bool verbose);
bool	path_can_read(const char *path, bool verbose);
bool	path_can_write(const char *path, bool verbose);
bool	path_can_exists(const char *path, bool verbose);
bool	path_check_mask(const char *path, int mask, bool verbose);

//path/path_pathfile.c
bool	path_get_pathname(t_minishell *shell, t_cmd *cmd, char **pathname);

//path/path_types.c
bool	path_get_type(const char *path, t_path_types *type, bool verbose);
bool	path_is_directory(const char *path, bool *is_dir, bool verbose);
bool	path_is_file(const char *path, bool *is_file, bool verbose);

#endif