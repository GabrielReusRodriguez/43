/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/30 21:34:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

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

void	ft_print_node(t_list *node)
{
	if (node != NULL)
		printf("NODO Encontrado _%s_\n", (char *)node->data);
	else
		printf("NODO NO encontrado\n");
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*list2;
	char	*lista2[] = {"Gregorio", "Reu", "Rodr"};

	if (argc < 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	list = ft_list_push_strs(argc - 1, argv + 1);
	list2 = ft_list_push_strs(3, lista2);
	printf("PRE merge\n");
	printf("Lista 1\n");
	print_list(list);
	printf("Lista 2\n");
	print_list(list2);
	ft_list_merge(&list, list2);
	printf("POST merge\n");
	printf("Lista 1\n");
	print_list(list);
	printf("Lista 2\n");
	print_list(list2);
	return (0);
}
