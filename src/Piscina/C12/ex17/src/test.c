/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/01 00:35:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

static t_list	*ft_create_element(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

static void	ft_insert_node(t_list **begin_list, t_list *prev, t_list *node,
			t_list *new_node)
{
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		return ;
	}
	if (prev == NULL)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
		return ;
	}
	prev->next = new_node;
	new_node->next = node;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_node;
	t_list	*node;
	t_list	*prev;

	node = *begin_list;
	prev = NULL;
	new_node = ft_create_element(data);
	if (new_node == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		return ;
	}
	while (node->next != NULL && (*cmp)(node->data, new_node->data) < 0)
	{
		prev = node;
		node = node->next;
	}
	if ((*cmp)(node->data, new_node->data) < 0)
	{
		prev = node;
		node = node->next;
	}
	ft_insert_node(begin_list, prev, node, new_node);
}

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

	i = size - 1;
	while (i >= 1)
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
		i--;
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

int	main(int argc, char **argv)
{
	t_list			*list;
	t_list			*list2;
	int				i;

	if (argc < 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	printf("Init list: \n");
	list = NULL;
	ft_sorted_list_insert(&list, "Gabriel", ft_cmp);
	ft_sorted_list_insert(&list, "Reus", ft_cmp);
	ft_sorted_list_insert(&list, "Barcelona", ft_cmp);
	ft_sorted_list_insert(&list, "Badalona", ft_cmp);
	ft_sorted_list_insert(&list, "Zaragoza", ft_cmp);
	ft_sorted_list_insert(&list, "Chequia", ft_cmp);
	print_list(list);
	list2 = NULL;
	i = 1;
	while (i < argc)
	{
		ft_sorted_list_insert(&list2, argv[i], ft_cmp);
		i++;
	}
	print_list(list2);
	printf("Procedemos a merge\n");
	ft_sorted_list_merge(&list, list2, ft_cmp);
	printf("Sorted: \n");
	print_list(list);
	return (0);
}
