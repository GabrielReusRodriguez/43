/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:33:53 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/29 23:11:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*node;

	node = begin_list;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
