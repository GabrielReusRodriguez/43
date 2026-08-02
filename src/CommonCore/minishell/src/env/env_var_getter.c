/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:39:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 19:38:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "env/environment.h"
#include "env/var_cache.h"

static void init_value(char **value)
{
	if (*value != NULL)
		free (*value);
	*value = NULL;	
}

static bool	normalize_key(const char *_key, char **key)
{
	int	len;

	if (_key == NULL)
		return (ft_err_error("Error normilizing env_key"),false);
	if (_key[0] == '$')
	{
		len = ft_strlen(_key);
		*key = ft_substr(_key, 1, len - 1);
		if (*key == NULL)
			return (ft_err_errno(NULL), false);
	}
	else
	{
		*key = ft_strdup(_key);
		if (*key == NULL)
			return (ft_err_errno(NULL), false);		
	}
	return (true);
}


static bool	find_var(t_environment env, const char *key, char **value)
{
	t_pair	*pair;
	t_list	*node;
	
	if (var_is_in_cache(key))
		return (var_get_from_cache(&env, key, value));
	else
	{
		node = env.vars;
		while (node != NULL)
		{
			pair = (t_pair *)node->content;
			if (ft_strcmp(pair->key, key) == 0)
			{
				*value = ft_strdup(pair->value);
				if (*value == NULL)
					return (ft_err_errno(NULL), false);
				return (true);
			}
			node = node->next;
		}
	}
	return (true);
}

bool	env_get_var(t_environment env, const char *key, char **value)
{
	char	*_key;
	
	init_value (value);
	if(!normalize_key(key, &_key))
		return (false);
	if (!find_var(env, _key, value))
		return(free (_key), false);
	return (free (_key), true);
}