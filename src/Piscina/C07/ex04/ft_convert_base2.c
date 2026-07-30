/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:00:30 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/09 22:32:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_base(char *base)
{
	char	*aux;
	char	*str_base;
	int		size;

	str_base = base;
	size = 0;
	while (*str_base != '\0')
	{
		aux = base;
		aux++;
		while (*aux != '\0')
		{
			if (*aux == '+' || *aux == '-' || *aux == ' ')
				return (-1);
			if (*aux == *base)
				return (-1);
			aux++;
		}
		size++;
		str_base++;
	}
	return (size);
}

int	ft_is_in_base(char c, char *base)
{
	while (*base != '\0')
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	ft_check_sign(char **nbr, char *base)
{
	int	num_minus;

	num_minus = 0;
	while (**nbr != '\0' && (**nbr == '-' || **nbr == '+') && \
			ft_is_in_base(**nbr, base) == 0)
	{
		if (**nbr == '-')
			num_minus++;
		(*nbr)++;
	}
	if (num_minus % 2 == 1)
		return (-1);
	return (1);
}

unsigned int	ft_get_num_digits(unsigned int nbr, unsigned int size_base)
{
	unsigned int	num_digit;
	unsigned int	numero;

	num_digit = 1;
	numero = nbr;
	while (numero >= size_base)
	{
		numero = numero / size_base;
		num_digit++;
	}
	return (num_digit);
}
