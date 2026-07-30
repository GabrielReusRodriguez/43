/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/29 23:17:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

int	ft_list_size(t_list *begin_list);

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	node = ft_create_elem(data);
	if (node == NULL)
		return ;
	if (begin_list == NULL)
		node->next = NULL;
	else
		node->next = *begin_list;
	*begin_list = node;
}

int	main(int argc, char **argv)
{
	int		i;
	int		size;
	t_list	*list;

	if (argc < 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	list = NULL;
	i = 1;
	while (i < argc)
	{
		ft_list_push_front(&list, argv[i]);
		i++;
	}
	size = ft_list_size(list);
	printf("Size list : %d \n", size);
	return (0);
}
