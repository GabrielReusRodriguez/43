/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:24 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 21:22:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factor;
	int	total;

	if (nb < 0)
	{
		return (0);
	}
	factor = 1;
	total = 1;
	if (nb == 0)
		return (1);
	while (factor <= nb)
	{
		total = factor * total;
		factor++;
	}
	return (total);
}
