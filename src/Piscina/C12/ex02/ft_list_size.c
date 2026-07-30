/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:19:49 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/29 23:15:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
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
