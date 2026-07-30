/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 22:14:51 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/31 23:20:52 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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
