/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:03:24 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/21 04:00:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_primitives.h"
#include "ft_stack_utils.h"
#include "ft_sort.h"

#include <stdio.h>

// 5 2 1 => Si a > b sa 2 5 1 => Si a < b rda  1 2 5
/*
static void	ft_sort_3(t_stack **stack)
{
	while (ft_stack_issorted(*stack) == 0)
	{
		if (ft_stack_content(*stack) > ft_stack_content((*stack)->next))
		{
			printf("sa\n");
			ft_primitives_sx(stack);
			ft_stack_debug(*stack);
		}
		else
		{
			printf("rra\n");
			ft_primitives_rrx(stack);
			ft_stack_debug(*stack);
		}
	}
}
*/

int     ft_are_sorted_values(int first, int next, int order)
{
	if (order == ORDER_ASC)
	{
		if (first <= next)
			return (1);
	}
	if (order == ORDER_DESC)
	{
		if (first >= next)
			return (1);
	}
	return (0);	

}

static int ft_sort3_next_mov(t_stack **stack, int order)
{
	int	content;
	int	content_next;

	content = ft_stack_content(*stack);
	content_next = ft_stack_content((*stack)->next);
	if (ft_stack_issorted(*stack, order) == 0)
	{
		if (ft_are_sorted_values(content, content_next, order) == 0)
			return (PRIMITIVE_SA);
		else
			return (PRIMITIVE_RRA);
	}
	else
	return (PRIMITIVE_NO);
	
}

static void	ft_execute_step(int stacka_action, int stackb_action, t_stack **stack_a, t_stack **stack_b)
{
	if (stacka_action == PRIMITIVE_RA && stackb_action == PRIMITIVE_RB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RR);
		return ;
	}
	if (stacka_action == PRIMITIVE_SA && stackb_action == PRIMITIVE_SB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SS);
		return ;
	}
	if (stacka_action == PRIMITIVE_RRA && stackb_action == PRIMITIVE_RRB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRR);
		return ;
	}
	ft_execute_action(stack_a, NULL, stacka_action);
	ft_execute_action(NULL, stack_b, stackb_action);

}

#include <stdio.h>

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_size;
	int		stacka_action;
	int		stackb_action;
	size_t		i;
	
	*stack_b = NULL;
	if (ft_stack_isempty(stack_a) == 1)
		return ;
	else
	{
		stack_size = ft_stack_size(*stack_a);
		if (stack_size == 3)
		{
			while(ft_stack_isnsorted(*stack_a, 3, ORDER_ASC) == 0 || ft_stack_isnsorted(*stack_b, 0, ORDER_ASC) == 0)
			{
				stacka_action = ft_sort3_next_mov(stack_a, ORDER_ASC);
				//stackb_action = ft_sort3_next_mov(stack_b, ORDER_DESC);
				ft_execute_step(stacka_action, PRIMITIVE_NO, stack_a, stack_b);
			}
			return ;
		}
		if (stack_size == 5)
		{
			ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
			ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
			/*
			Para oredenar la pila b, puedo hcaer un truco.
			Revisar si está desordenada y si lo está... hacemos en reverse cuando lo tenga que hacer la pila a con 3. 
			Si la pila A NO lo ha ehcho, entonces al salir lo hago pero en el peor de los casos tenemos 2 movimientos en vez de 3

			*/
			while(ft_stack_isnsorted(*stack_a, 3, ORDER_ASC) == 0)
			{
				stacka_action = ft_sort3_next_mov(stack_a, ORDER_ASC);
				stackb_action= PRIMITIVE_NO;
				if( ft_stack_issorted(*stack_b, ORDER_ASC) == 0 && stacka_action == PRIMITIVE_RRA)
					stackb_action = PRIMITIVE_RRB;
				//stackb_action = ft_sort3_next_mov(stack_b, ORDER_ASC);
				//if (stackb_action != PRIMITIVE_NO)
				//stackb_action = stackb_action + 1;
				ft_execute_step(stacka_action, stackb_action, stack_a, stack_b);
			}
			if( ft_stack_issorted(*stack_b, ORDER_ASC) == 0)
				ft_execute_step(PRIMITIVE_NO, PRIMITIVE_RB, stack_a, stack_b);

		/*
			while(ft_stack_isnsorted(*stack_a, 3, ORDER_ASC) == 0 || ft_stack_isnsorted(*stack_b, 2, ORDER_ASC) == 0)
			{
				stacka_action = ft_sort3_next_mov(stack_a, ORDER_ASC);
				stackb_action = ft_sort3_next_mov(stack_b, ORDER_ASC);
				if (stackb_action != PRIMITIVE_NO)
					stackb_action = stackb_action + 1;
				ft_execute_step(stacka_action, stackb_action, stack_a, stack_b);
			}
		*/	
	/*
			printf("PILAS ORDENADAS\n");
			ft_stack_debug(*stack_a);
			ft_stack_debug(*stack_b);
	*/		
			//Falta el caso que el stack b sea mayor que todo el stack a
			i = 0;
			while(ft_stack_isempty(stack_b) == 0)
			{
				if (ft_are_sorted_values(ft_stack_content(*stack_a), ft_stack_content(*stack_b), ORDER_ASC) == 1)
				{
					if(i == 3 - 1)
						ft_execute_action(stack_a,stack_b, PRIMITIVE_RR);
					else
					{
						ft_execute_action(stack_a,stack_b, PRIMITIVE_RA);
					}
					i++;
				}
				else
				{
					ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
					i--;
				}
				/*
				printf("PRE-i %lu\n",i);
				ft_stack_debug(*stack_a);
				ft_stack_debug(*stack_b);
				*/
				if( i == 3 )
				{
					
					if (ft_are_sorted_values(ft_stack_content(*stack_a), ft_stack_content(*stack_b),ORDER_ASC) == 0)
					{
						ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
					}
					else
					{
						//ft_execute_action(stack_a,stack_b, PRIMITIVE_SB);
						while (ft_stack_isempty(stack_b) == 0)
							ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
					}
					/*
					if (ft_are_sorted_values(ft_stack_content(*stack_a), ft_stack_content(*stack_b),ORDER_ASC) == 1)
					{
						ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
						ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
						ft_execute_action(stack_a,stack_b, PRIMITIVE_SA);
					
					}
					
					while(ft_stack_isempty(stack_b) == 0)
					{
						ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
					}
					*/
				}

			}
			/*
			printf("RE-orden\n");
			ft_stack_debug(*stack_a);
			*/
			while(ft_stack_issorted(*stack_a,ORDER_ASC) == 0)
			{	
				ft_execute_action(stack_a,stack_b, PRIMITIVE_RA);
				//ft_stack_debug(*stack_a);
			}
		}
	}
}