/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:58:45 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 20:10:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
			*data_ref, int (*cmp)())
{
	t_list	*node;

	node = begin_list;
	while (node->next != NULL)
	{
		if ((*cmp)(node->data, data_ref) == 0)
			(*f)(node->data);
		node = node->next;
	}
	if ((*cmp)(node->data, data_ref) == 0)
		(*f)(node->data);
}
