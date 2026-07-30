/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/30 20:21:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

int	ft_cmp(void *st1, void *st2)
{
	char	*str1;
	char	*str2;
	int		cmp;

	str1 = (char *)st1;
	str2 = (char *)st2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		cmp = *str1 - *str2;
		if (cmp != 0)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

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
	t_list	*node;

	if (argc < 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	list = ft_list_push_strs(argc - 1, argv + 1);
	print_list(list);
	node = ft_list_find(list, "Reus", ft_cmp);
	ft_print_node(node);
	node = ft_list_find(list, "Pimpollo", ft_cmp);
	ft_print_node(node);
	return (0);
}
