/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cache.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:53:33 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/16 21:36:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "env/environment.h"
#include "env/var_cache.h"
#include "libft.h"

bool	var_is_in_cache(const char * var_name)
{
	if (ft_strcmp(VAR_CACHE_PATH, var_name) == 0)
		return (true);
	if (ft_strcmp(VAR_CACHE_PWD, var_name) == 0)
		return (true);
	return (false);
}

bool	var_get_from_cache(t_environment *env, const char * var_name, \
			char **var_value)
{
	t_pair	*pair;
	
	pair = NULL;
	*var_value = NULL;
	if (ft_strcmp(VAR_CACHE_PATH, var_name) == 0)
		pair = env->var_cache.path;
	if (ft_strcmp(VAR_CACHE_PWD, var_name) == 0)
		pair = env->var_cache.pwd;
	if (pair == NULL)
		return (NULL);
	*var_value = ft_strdup(pair->value);
	if (*var_value == NULL)
		return (ft_err_errno(NULL), false);
	return (true);	
}