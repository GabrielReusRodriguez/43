/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:00:48 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 19:55:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

static t_list	*ft_list_at(t_list *list, unsigned int pos)
{
	unsigned int	i;
	t_list			*node;

	i = 0;
	node = list;
	while (i < pos && node->next != NULL)
	{
		node = node->next;
		i++;
	}
	if (i == pos)
		return (node);
	else
		return (NULL);
}

static unsigned int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 1;
	while (begin_list->next != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_reverse(t_list **begin_list)
{
	unsigned int	size;
	unsigned int	i;
	t_list			*node;
	t_list			*prev;
	t_list			*list;

	size = ft_list_size(*begin_list);
	i = size - 1;
	list = *begin_list;
	while (i > 0)
	{
		node = ft_list_at(list, i);
		prev = ft_list_at(list, i - 1);
		node->next = prev;
		if (i == size - 1)
			*begin_list = node;
		i--;
	}
	list->next = NULL;
}
