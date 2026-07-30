/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:22:52 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 21:21:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static	void	ft_free_node(t_list *node, void (*free_fct)(void *))
{
	(*free_fct)(node->data);
	free(node);
}

static	void	ft_remove_node(t_list **prev, t_list **node,
			t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*aux;

	aux = *node;
	if (*prev == NULL)
		*begin_list = (*node)->next;
	else
		(*prev)->next = (*node)->next;
	*node = (*node)->next;
	ft_free_node(aux, free_fct);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list			*node;
	t_list			*prev;

	node = *begin_list;
	prev = NULL;
	while (node->next != NULL)
	{
		if ((*cmp)(node->data, data_ref) == 0)
		{
			ft_remove_node(&prev, &node, begin_list, free_fct);
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
	if ((*cmp)(node->data, data_ref) == 0)
	{
		prev->next = NULL;
		ft_free_node(node, free_fct);
	}
}
