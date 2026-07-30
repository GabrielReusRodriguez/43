/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:51:52 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 00:40:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*node;
	t_list	*node_to_free;

	node = begin_list;
	while (node->next != NULL)
	{
		(*free_fct)(node->data);
		node_to_free = node;
		node = node->next;
		free(node_to_free);
	}
	(*free_fct)(node->data);
	free (node);
}
