/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/29 01:20:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

void	print_list(t_list *begin_list)
{
	t_list	*node;

	printf("Lista 1: \n");
	node = begin_list;
	printf("Lista: \n");
	if (node == NULL)
	{
		printf("node es null\n");
	}
	while (node->next != NULL)
	{
		printf("\t _%s_\n", (char *)node->data);
		node = node->next;
	}
	printf("\t Ultimo nodo es: _%s_\n", (char *)node->data);
	printf("Fin lista: \n");
}

int	main(int argc, char **argv)
{
	int		i;
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
	printf("PRE-print\n");
	print_list(list);
	return (0);
}
