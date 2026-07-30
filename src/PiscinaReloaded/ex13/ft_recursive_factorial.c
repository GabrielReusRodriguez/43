/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:36:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 18:55:46 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_recursive_factorial(int nb)
{
	unsigned long	total;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	total = (unsigned long)nb;
	total = total * (unsigned long)ft_recursive_factorial(nb - 1);
	if (total > (unsigned long)INT_MAX)
		return (0);
	return ((int)total);
}
/*
#include <stdio.h>
int main(void)
{
	int valor;

	valor = -71;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 78;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 0;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 1;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 2;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 12;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 10;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 11;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 5;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = 6;
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));

	valor = INT_MAX - 1;
	//printf("Factorial de %d \n",valor);
	printf("Factorial de %d es %d \n",valor,ft_recursive_factorial(valor));



	return(0);
}
*/
