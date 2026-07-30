/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:28:44 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/28 23:28:56 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strcmp(char *str1, char *str2)
{
	int	cmp;

	while (*str1 != '\0' && *str2 != '\0')
	{
		cmp = *str1 - *str2;
		if (cmp != 0)
			return (cmp);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

static unsigned int	ft_get_size_ptr(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*ptr;

	size = ft_get_size_ptr(tab);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if ((tab[j] != NULL ) && ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ptr = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = ptr;
			}
			j++;
		}
		i++;
	}
}
