/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:36:43 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/13 19:02:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

static char	*ft_copy_ptr(char *str, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	ft_add_lastnode(struct s_stock_str *stock)
{
	stock->str = NULL;
}

static int	ft_get_ptr_size(char *string)
{
	int	size;

	size = 0;
	while (*string != '\0')
	{
		size++;
		string++;
	}
	return (size);
}

static struct s_stock_str	*ft_fill_structure(struct s_stock_str *ptr, \
		char *str)
{
	ptr->str = str;
	ptr->size = ft_get_ptr_size(ptr->str);
	ptr->copy = ft_copy_ptr(str, ptr->size);
	if (ptr->copy == NULL)
		return (NULL);
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int						i;
	struct s_stock_str		*ptr;

	ptr = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (ft_fill_structure(&ptr[i], av[i]) == NULL)
		{
			free (ptr);
			return (NULL);
		}
		i++;
	}
	ft_add_lastnode(ptr + i);
	return (ptr);
}
