/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:28:20 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/21 04:04:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_stack.h"
#include "ft_validations.h"
#include "ft_primitives.h"
#include "ft_sort.h"


void	*push_new_content(const char *str_number, t_stack **stack)
{
	t_stack	*node;
	int		*content;

	content = (int *)malloc(sizeof(int));
	if (content == NULL)
	{
		ft_stack_clear(stack, free);
		return (NULL);
	}
	*content = ft_atoi(str_number);
	node = ft_stack_newnode(content);
	if (node == NULL)
	{
		ft_stack_clear(stack, free);
		return (NULL);
	}
	ft_stack_push(stack, node);
	return (node);
}

t_stack	*fill_stack(int argc, char **argv)
{
	int			i;
	t_stack		*stack;

	stack = NULL;
	/* Primer argv = cima del stack: push desde el último argumento. */
	i = argc - 1;
	while (i >= 1)
	{
		if (ft_isvalid_arg(argv[i]) == 0)
		{
			printf("Hay un arg con formato invalido: _%s_\n", argv[i]);
			return (NULL);
		}
		if (push_new_content(argv[i], &stack) == NULL)
			return (NULL);
		i--;
	}
	/*
	i = 1;
	while (i < argc)
	{
		if (ft_isvalid_arg(argv[i]) == 0)
		{
			printf("Hay un arg con formato invalido: _%s_\n", argv[i]);
			return (NULL);
		}
		if (push_new_content(argv[i], &stack) == NULL)
			return (NULL);
		i++;
	}
	*/
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 4)
	{
		printf("Numero erroneo de args\n");
		return (1);
	}
	//printf("Init\n");
	stack_a = fill_stack(argc, argv);
	//printf("Stack_a filled\n");
	stack_b = fill_stack(0, NULL);
	//printf("Stack b filled\n");
	if (ft_isvalid_stack(&stack_a) == 0)
	{
		printf("Numeros repetidos\n");
		return (1);
	}
	//printf("Init\n");
	//ft_stack_debug(stack_a);
//	ft_stack_debug(stack_b);

	ft_sort(&stack_a, &stack_b);
	//printf("FINAL ******************************************\n");
	/*
	ft_stack_debug(stack_a);
	ft_stack_debug(stack_b);
*/
	ft_stack_clear(&stack_a, free);
	ft_stack_clear(&stack_b, free);
	return (0);
}
