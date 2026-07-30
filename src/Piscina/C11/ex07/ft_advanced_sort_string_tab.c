/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:24:20 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/28 23:36:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((tab[j] != NULL ) && (*cmp)(tab[j], tab[j + 1]) > 0)
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
