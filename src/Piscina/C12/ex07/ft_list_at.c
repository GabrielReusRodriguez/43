/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:45:44 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/30 00:59:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*node;

	i = 0;
	node = begin_list;
	if (begin_list == NULL)
		return (NULL);
	while (i < nbr && node->next != NULL)
	{
		node = node->next;
		i++;
	}
	if (i == nbr)
		return (node);
	else
		return (NULL);
}
