/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:18:13 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 17:15:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../ft_abs.h"


int	main(int argc, char **argv)
{
	(void)argv;
	argc++;
	int valor;

	valor = INT_MIN;
	printf("abs de %d es: %d",valor, ABS(valor));
	valor = 0;
	printf("abs de %d es: %d",valor, ABS(valor));
	valor = INT_MAX;
	printf("abs de %d es: %d",valor, ABS(valor));
	return (0);
}