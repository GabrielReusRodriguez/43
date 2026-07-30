/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:18:13 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 17:15:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

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

int main(int argc, char **argv)
{
	struct s_stock_str * ptr;

	ptr = ft_strs_to_tab(argc - 1 ,argv + 1);
	//ptr = ft_strs_to_tab(0,argv);
	if (ptr == NULL)
	{
		printf("ERROR\n");
		return (1);
	}
	ft_show_tab(ptr);
	return (0);
}
