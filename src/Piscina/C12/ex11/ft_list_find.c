/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:12:30 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 20:16:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	node = begin_list;
	while (node->next != NULL)
	{
		if ((*cmp)(node->data, data_ref) == 0)
			return (node);
		node = node->next;
	}
	if ((*cmp)(node->data, data_ref) == 0)
		return (node);
	else
		return (NULL);
}
