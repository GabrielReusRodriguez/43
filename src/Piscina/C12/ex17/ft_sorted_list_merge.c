/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:24:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/01 00:51:09 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

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

static void	ft_sorted_list_insert(t_list **begin_list,
		t_list *new_node, int (*cmp)())
{
	t_list	*node;
	t_list	*prev;

	node = *begin_list;
	prev = NULL;
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	t_list	*node;
	t_list	*next;

	node = begin_list2;
	while (node->next != NULL)
	{
		next = node->next;
		ft_sorted_list_insert(begin_list1, node, cmp);
		node = next;
	}
	ft_sorted_list_insert(begin_list1, node, cmp);
}
