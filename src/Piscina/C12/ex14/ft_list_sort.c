/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:37:00 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/31 21:56:28 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

unsigned int	ft_size_list(t_list *list)
{
	unsigned int	size;

	if (list == NULL)
		return (0);
	size = 1;
	while (list->next != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}

static t_list	*ft_swap(t_list *node1, t_list *node2)
{
	void	*data;

	data = node1->data;
	node1->data = node2->data;
	node2->data = data;
	return (node2);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list			*node;
	unsigned int	size;
	unsigned int	i;

	node = *begin_list;
	i = 0;
	size = ft_size_list(*begin_list);
	while (i < size)
	{
		node = *begin_list;
		while (node->next != NULL)
		{
			if ((*cmp)(node->data, node->next->data) > 0)
				node = ft_swap(node, node->next);
			if (node->next != NULL)
				node = node->next;
		}
		i++;
	}
}
