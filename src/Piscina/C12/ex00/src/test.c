/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/29 23:14:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_list.h"

t_list	*ft_create_elem(void *data);

int	main(int argc, char **argv)
{
	t_list	*node;

	if (argc != 2)
	{
		printf("Wrong number of args");
		return (1);
	}
	node = ft_create_elem(argv[1]);
	printf("DATA: _%s_\n", (char *)node->data);
	if (node->next == NULL)
	{
		printf("NEXT es NULL\n");
	}
	else
	{
		printf("NEXT NO es NULL\n");
	}
	return (0);
}
