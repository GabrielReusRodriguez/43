/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:00:08 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/09 22:34:26 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_check_base(char *base);
int	ft_check_sign(char **nbr, char *base);
int	ft_get_num_digits(int nbr, int size_base);

unsigned int	ft_from_base_to_uint(char *nbr, int base_size, char *base_from)
{
	unsigned int	number;
	int				i;

	number = 0;
	while (*nbr != '\0')
	{
		i = 0;
		while (base_from[i] != '\0' && base_from[i] != *nbr)
			i++;
		if (base_from[i] != '\0')
			number = number * base_size + i;
		else
			return (number);
		nbr++;
	}
	return (number);
}

char	*ft_from_uint_to_base(unsigned int nbr, char *base_to, \
		int base_size, int sign)
{
	char				*number;
	unsigned int		size_string;
	unsigned int		numero;
	int					i;

	size_string = ft_get_num_digits(nbr, base_size);
	i = 0;
	if (sign < 0)
		i = 1;
	number = (char *)malloc(size_string + i + 1);
	if (number == NULL)
		return (NULL);
	if (sign < 0)
		number[0] = '-';
	number[size_string + i] = '\0';
	numero = nbr;
	while (numero >= (unsigned int)base_size)
	{
		number[size_string + i -1] = base_to[numero % base_size];
		numero = numero / base_size;
		size_string--;
	}
	number[i] = base_to[numero];
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char				*str;
	int					size_base_from;
	int					size_base_to;
	int					sign;
	unsigned int		num;

	str = nbr;
	size_base_from = ft_check_base(base_from);
	size_base_to = ft_check_base(base_to);
	if (size_base_from <= 1 || size_base_to <= 1)
		return (NULL);
	sign = ft_check_sign(&str, base_from);
	num = ft_from_base_to_uint(str, size_base_from, base_from);
	str = ft_from_uint_to_base(num, base_to, size_base_to, sign);
	return (str);
}
