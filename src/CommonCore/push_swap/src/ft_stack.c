/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:01:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/16 12:00:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stack.h"

t_stack	*ft_stack_newnode(void *content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_stack_isempty(t_stack **stack)
{
	if (*stack == NULL)
		return (1);
	else
		return (0);
}

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	if(node != NULL)
	{
		if (ft_stack_isempty(stack) == 1)
		{
			node->next = NULL;
			*stack = node;
		}
		else
		{
			node->next = *stack;
			*stack = node;
		}
	}
}

t_stack	*ft_stack_pop(t_stack **stack)
{
	t_stack	*node;

	if (ft_stack_isempty(stack) == 1)
		return (NULL);
	else
	{
		node = *stack;
		*stack = (*stack)->next;
		return (node);
	}
}

size_t	ft_stack_size(const t_stack *stack)
{
	size_t	size;

	size = 0;
	if (stack == NULL)
		return (size);
	else
	{
		while (stack != NULL)
		{
			stack = stack->next;
			size++;
		}
	}
	return (size);
}
