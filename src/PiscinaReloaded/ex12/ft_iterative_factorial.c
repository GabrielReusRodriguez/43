/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 13:57:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	unsigned long	total;

	if (nb < 0)
		return (0);
	total = 1;
	while (nb > 0)
	{
		total = total * nb ;
		if (total > INT_MAX)
			return (0);
		nb--;
	}
	return ((int)total);
}
/*
#include <stdio.h>

int	main(void)
{
	int factorial;

	factorial = ft_iterative_factorial(90);
	printf("valor : %d\n",factorial);
	return (0);
}
*/
