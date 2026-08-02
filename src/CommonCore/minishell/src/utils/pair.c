/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:27:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:11:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "utils/pair.h"
#include "libft.h"

t_pair	pair_new(void)
{
	t_pair pair;

	pair.key = NULL;
	pair.value = NULL;
	return (pair);
}

bool	pair_init(t_pair *pair, const char *_key, const char *_value)
{
	if (_key == NULL || _value == NULL)
		return (ft_err_error("Initializing a pair wiht NULL field."), false);	
	*pair = pair_new();
	pair->key = ft_strdup(_key);
	if (pair->key == NULL)
		return (ft_err_errno(NULL), false);
	pair->value = ft_strdup(_value);
	if (pair->value == NULL)
	{
		pair_destroy(pair);
		ft_err_errno(NULL);
		return (false);
	}
	return (true);
}

bool	pair_update(t_pair *pair, const char *_key, const char *_value)
{
	if (_key == NULL || _value == NULL)
		return (ft_err_error("Updating a pair wiht NULL field."), false);
	pair_destroy(pair);
	return (pair_init(pair, _key, _value));
}

void	pair_destroy(t_pair *pair)
{
	if (pair->key != NULL)
		free (pair->key);
	if (pair->value != NULL)
		free (pair->value);
}

void	pair_free_node(void *node)
{
	t_pair *pair;

	pair = (t_pair *)node;
	if (pair != NULL)
	{
		pair_destroy(pair);
		free(pair);
	}
}