/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:23:31 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 13:22:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "env/environment.h"
#include "utils/pair.h"
#include "libft.h"

t_environment	env_new(void)
{
	t_environment env;

	env_init(&env);
	return (env);
}

void	env_init(t_environment *env)
{
	env->vars = NULL;
	env->var_cache.path = NULL;
	env->var_cache.pwd = NULL;	
}

static void	env_vars_free(void *var)
{
	t_pair	*pair;

	pair = (t_pair *)var;
	pair_destroy(pair);
	free (pair);
}

void	env_destroy(t_environment *env)
{
	if (env->vars != NULL)
		ft_lstclear(&env->vars, env_vars_free);
	env->var_cache.path = NULL;
	env->var_cache.pwd = NULL;	
}