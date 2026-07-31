/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:02:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/17 23:28:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_stack.h"

# define ORDER_ASC 0
# define ORDER_DESC 1

int     ft_are_sorted_values(int first, int next, int order);
void	ft_sort(t_stack **stack, t_stack **stack_b);

#endif