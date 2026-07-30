/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:57:27 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/31 22:13:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "ft_list.h"

static unsigned int	ft_get_size_list(t_list *list)
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

static t_list	*ft_list_at(t_list *list, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	if (list == NULL)
		return (NULL);
	while (i < pos && list->next != NULL)
	{
		list = list->next;
		i++;
	}
	if (i == pos)
		return (list);
	else
		return (NULL);
}

static void	ft_swap(t_list *node1, t_list *node2)
{
	t_list	aux;

	aux = *node1;
	node1->data = node2->data;
	node2->data = aux.data;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	i;
	unsigned int	j;
	t_list			*node_i;
	t_list			*node_j;

	i = 0;
	j = ft_get_size_list(begin_list) - 1;
	while (i < j)
	{
		node_i = ft_list_at(begin_list, i);
		node_j = ft_list_at(begin_list, j);
		ft_swap(node_i, node_j);
		i++;
		j--;
	}
}
