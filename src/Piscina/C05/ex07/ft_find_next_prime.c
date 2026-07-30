/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:16:16 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/06 15:46:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Utilizamos el postulado de Bertrands que dice que para cada numero entero 
 * n > 3, existe POR LO MENOS un entero primo p entre n < p < 2n -2 
 * */

#include <limits.h>

static int	ft_check_is_prime(int nb)
{
	int	factor;

	factor = 2;
	if (nb == INT_MAX)
		return (1);
	while (factor * factor <= nb)
	{
		if (nb % factor == 0)
			return (0);
		factor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	high_limit;
	int	aux;
	int	i;

	if (nb <= 2)
		return (2);
	i = 0;
	if (nb >= INT_MAX / 2)
		high_limit = INT_MAX;
	else
		high_limit = 2 * nb - 2;
	while (nb + i <= high_limit)
	{
		if (nb + i > INT_MAX)
			aux = INT_MAX;
		else
			aux = nb + i;
		if (ft_check_is_prime(aux) == 1)
			return (aux);
		i++;
	}
	return (0);
}
