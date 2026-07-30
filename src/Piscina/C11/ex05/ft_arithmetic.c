/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithmetic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:29:02 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 12:58:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	add(int value1, int value2)
{
	return (value1 + value2);
}

int	substract(int value1, int value2)
{
	return (value1 - value2);
}

int	divide(int value1, int value2)
{
	return (value1 / value2);
}

int	mod(int value1, int value2)
{
	return (value1 % value2);
}

int	multiply(int value1, int value2)
{
	return (value1 * value2);
}
