/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:40:07 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/29 23:18:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*node;

	new_node = ft_create_elem(data);
	if (new_node == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
		return ;
	}
	node = *begin_list;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = new_node;
}
