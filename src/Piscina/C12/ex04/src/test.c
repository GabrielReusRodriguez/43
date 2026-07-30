/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/29 23:19:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data);

void	print_list(t_list *list)
{
	t_list	*node;

	node = list;
	printf("Lista...\n");
	while (node->next != NULL)
	{
		printf("\t valor = _%s_\n", (char *)node->data);
		node = node->next;
	}
	printf("\tUltimo valor = _%s_\n", (char *)node->data);
	printf("Fin Lista...\n");
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
		ft_list_push_back(&list, argv[i]);
		i++;
	}
	print_list(list);
	return (0);
}
