/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cache.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:05:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/16 21:35:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_CACHE_H
# define VAR_CACHE_H

# include "utils/pair.h"
//# include "env/environment.h"

# define VAR_CACHE_PATH		"path"
# define VAR_CACHE_PWD		"pwd"


typedef struct s_environment t_environment;

typedef struct s_var_cache
{
	t_pair	*path;
	t_pair	*pwd;

}	t_var_cache;

bool	var_is_in_cache(const char * var_name);
bool	var_get_from_cache(t_environment *env, const char * var_name, \
			char **var_value);

#endif