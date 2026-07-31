/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_px.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:50:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 21:09:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_primitives_px(t_stack **src,t_stack **dest)
{
	t_stack	*src_node;

	src_node = ft_stack_pop(src);
	ft_stack_push(dest,src_node);
}