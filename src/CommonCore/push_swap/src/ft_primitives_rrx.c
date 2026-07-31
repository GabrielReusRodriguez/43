/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_rrx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:50:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/16 00:28:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"
#include "ft_stack_utils.h"

void	ft_primitives_rrx(t_stack **stack)
{
	int		*contents;
	size_t	stack_size;
	t_stack	*node;
	size_t	i;

	if (ft_stack_isempty(stack) == 0)
	{
		stack_size = ft_stack_size(*stack);
		contents = ft_stack_to_array(stack);
		if (contents == NULL)
			return ;

		i = 0;
		node = *stack;
		*((int *)node->content) = contents[stack_size -1];
		node = node->next;
		while (node != NULL)
		{
			*((int *)node->content) = contents[i];
			i++;
			node = node->next;
		}
		free (contents);

		/*
		stack_size = ft_stack_size(*stack);
		contents = ft_stack_to_array(stack);
		if (contents == NULL)
			return ;
		i = stack_size - 1;
		node = *stack;
		while (i > 0)
		{
			*((int *)node->content) = contents[i - 1];
			i--;
			node = node->next;
		}
		*((int *)node->content) = contents[stack_size - 1];
		free (contents);
		*/
	}

}

void	ft_primitives_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_primitives_rrx(stack_a);
	ft_primitives_rrx(stack_b);
}
