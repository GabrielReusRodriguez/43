/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:24:40 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/01 19:21:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

static unsigned int	ft_num_digits(unsigned long long nb)
{
	unsigned int	num_digits;

	num_digits = 1;
	while (nb / 16 != 0)
	{
		nb = nb / 16;
		num_digits++;
	}
	return (num_digits);
}

static void	ft_get_characters( char *ch_number, unsigned int size,
			unsigned long long number, bool upcase)
{
	int				i;
	unsigned int	digit;

	i = size - 1;
	while (i >= 0)
	{
		digit = (number % 16);
		if (digit < 10)
			ch_number[i] = '0' + digit;
		else
		{
			if (upcase)
				ch_number[i] = 'A' + digit - 10;
			else
				ch_number[i] = 'a' + digit - 10;
		}
		number = number / 16;
		i--;
	}
}

char	*ft_htoa(unsigned long long num, bool upcase)
{
	char			*number;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = ft_num_digits(num);
	number = (char *)malloc(size + 1);
	if (number == NULL)
		return (NULL);
	ft_get_characters(number + i, size - i, num, upcase);
	number[size] = '\0';
	return (number);
}
