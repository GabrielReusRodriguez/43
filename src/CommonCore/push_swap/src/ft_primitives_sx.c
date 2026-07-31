/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_sx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:50:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 22:32:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_primitives_sx(t_stack **stack)
{
	t_stack	*top_node;
	t_stack	*second_node;

	if (ft_stack_size(*stack) > 1)
	{
		top_node = ft_stack_pop(stack);
		second_node = ft_stack_pop(stack);
		ft_stack_push(stack, top_node);
		ft_stack_push(stack, second_node);
	}
}

void	ft_primitives_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_primitives_sx(stack_a);
	ft_primitives_sx(stack_b);
}