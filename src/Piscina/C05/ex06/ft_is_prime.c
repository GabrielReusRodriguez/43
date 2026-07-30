/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:39:14 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/06 19:01:08 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_is_prime(int nb)
{
	int	factor;

	if (nb < 2)
		return (0);
	if (nb == INT_MAX)
		return (1);
	factor = 2;
	while (factor * factor <= nb)
	{
		if (nb % factor == 0)
			return (0);
		factor++;
	}
	return (1);
}
