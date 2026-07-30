/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:30:51 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 19:26:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Metodo de newton para obtener raices cuadradas*/
/* CHULETA: Para cada iteracion calcula la formula (x0 + nb /x0) / 2 
 * xq al hacer la operacion, sera (x0^2 +nb ) / 2 
 * cuando  x0^ 2 sea nb , al dividirlo por 2 nos saldra aprox. nb.
 * El while es x1 < x0   es decir, cuando tenemos convergencia del valor actual 
 * y el anterior (ambos son iguales o nos estamos "alejando"  , sale del while.
 *  */
int	ft_sqrt(int nb)
{
	int	x0;
	int	x1;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	x0 = nb / 2;
	x1 = (x0 + nb / x0) / 2;
	while (x1 < x0)
	{
		x0 = x1;
		x1 = (x0 + nb / x0) / 2;
	}
	if (x0 * x0 != nb)
	{
		return (0);
	}
	return (x0);
}
/*
#include <stdio.h>
#include <limits.h>
int main()    
{
	int valor;
	//valor = INT_MAX;
	valor = 1119365;
	printf("SQRT %d es %d \n", valor, ft_sqrt(valor));
	return (0);
}
*/
