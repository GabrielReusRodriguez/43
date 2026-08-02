/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_appends.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:35:57 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/21 21:45:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"

static int	get_size(char **str_vector)
{
	int i;

	i = 0;
	while (str_vector[i] != NULL)
		i++;
	return (i);
}

static bool	get_memory(int num, char ***vector)
{
	char **new_vector;

	new_vector = (char **)malloc((num + 1) * sizeof(char *));
	if (new_vector == NULL)
		return (ft_err_errno(NULL), false);
	new_vector[num] = NULL;
	*vector = new_vector;
	return (true);
}

bool	utils_dchar_append_back(char ***vector, char *new_str)
{
	int 	size;
	int 	i;
	char	**new_vector;

	if (new_str == NULL)
		return(true);
	size = get_size(*vector);
	size++;
	if (!get_memory(size, &new_vector))
		return (false);
	i = 0;
	while((*vector)[i] != NULL)
	{
		new_vector[i] = (*vector)[i];
		i++;
	}
	new_vector[i] = new_str;
	//ft_ptr_free_dchar_ptr(*vector);
	free(*vector);
	*vector = new_vector;
	return (true);
}

bool	utils_dchar_append_front(char ***vector, char *new_str)
{
	int 	size;
	int 	i;
	char	**new_vector;

	if (new_str == NULL)
		return(true);
	size = get_size(*vector);
	size++;
	if (!get_memory(size, &new_vector))
		return (false);
	new_vector[0] = new_str;
	i = 0;
	while ((*vector)[i] != NULL)
	{
		new_vector[i + 1] = (*vector)[i];
		i++;
	}
	//ft_ptr_free_dchar_ptr(*vector);
	free(*vector);
	*vector = new_vector;
	return (true);	
}