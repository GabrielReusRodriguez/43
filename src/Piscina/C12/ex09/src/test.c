/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/30 19:54:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

char	*ft_strdup(char *ptr)
{
	int		size;
	int		i;
	char	*dup;

	size = 0;
	while (ptr[size] != '\0')
	{
		size++;
	}
	dup = (char *)malloc((size + 1));
	i = 0;
	while (i < size)
	{
		dup[i] = ptr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = ft_strdup(data);
	node->next = NULL;
	return (node);
}

/*
Hay que hacer push front y dejar apuntando al primer elemento de la lista. 
( ultimo de la tabla)
*/
t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*node;
	int		i;

	i = 0;
	while (i < size)
	{
		node = ft_create_elem(strs[i]);
		if (node == NULL)
			return (NULL);
		if (i == 0)
			list = node;
		else
		{
			node->next = list;
			list = node;
		}
		i++;
	}
	return (list);
}

void	print_list(t_list *list)
{
	t_list	*node;

	node = list;
	printf("Lista...\n");
	while (node->next != NULL)
	{
		printf("\t valor = _%s_\n", (char *)node->data);
		node = node->next;
	}
	printf("\tUltimo valor = _%s_\n", (char *)node->data);
	printf("Fin Lista...\n");
}

void	ft_to_upper(void *data)
{
	char	*my_data;

	my_data = (char *)data;
	while (*my_data != '\0')
	{
		if ((*my_data >= 'a' && *my_data <= 'z'))
			*my_data = *my_data - 32;
		my_data++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	list = ft_list_push_strs(argc - 1, argv + 1);
	print_list(list);
	ft_list_foreach(list, ft_to_upper);
	printf("Foreached...\n");
	print_list(list);
	return (0);
}
