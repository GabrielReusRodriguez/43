/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:34:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/17 23:43:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_validations.h"
#include "ft_stack_utils.h"
#include "libft.h"
#include "ft_sort.h"

int	ft_isvalid_arg(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_isvalid_stack(t_stack **stack)
{
	t_stack	*node_review;
	t_stack	*node_aux;
	size_t	num_occurs;

	if (*stack == NULL)
		return (0);
	node_review = *stack;
	while (node_review != NULL)
	{
		num_occurs = 0;
		node_aux = *stack;
		while (node_aux != NULL)
		{
			if (ft_stack_content(node_aux) == ft_stack_content(node_review))
				num_occurs++;
			if (num_occurs > 1)
				return (0);
			node_aux = node_aux->next;
		}
		node_review = node_review->next;
	}
	return (1);
}

int	ft_stack_issorted(const t_stack *stack, int order)
{
	t_stack	*node;
	int		content;
	int		content_next;

	if (stack == NULL)
		return (1);
	node = (t_stack *)stack;
	while (node->next != NULL)
	{
		content = ft_stack_content(node);
		content_next = ft_stack_content(node->next);
		//if (content > content_next)
		if(ft_are_sorted_values(content, content_next, order) == 0)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_stack_isnsorted(const t_stack *stack, size_t n, int order)
{
	t_stack	*node;
	int		content;
	int		content_next;
	size_t	i;

	if (stack == NULL)
		return (1);
	i = 0;
	node = (t_stack *)stack;
	while (node->next != NULL && i < n)
	{
		content = ft_stack_content(node);
		content_next = ft_stack_content(node->next);
		//if (content > content_next)
		if (ft_are_sorted_values(content, content_next, order) == 0)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}