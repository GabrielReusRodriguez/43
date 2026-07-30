/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:21:32 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 21:11:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_manage_sign(char **nbr)
{
	int	num_minus;

	num_minus = 0;
	while ((**nbr == ' ' || **nbr == '\t' || **nbr == '\v' || **nbr == '\f')
		&& **nbr != '\0')
	{
		(*nbr)++;
	}
	while (**nbr == '-' || **nbr == '+')
	{
		if (**nbr == '-')
			num_minus++;
		(*nbr)++;
	}
	if (num_minus % 2 == 1)
		return (-1);
	else
	{
		return (1);
	}
}

static int	ft_check_base(char *base, int *size)
{
	char	*string;

	*size = 0;
	while (*base != '\0')
	{
		if (*base == ' ' || *base == '+' || *base == '-')
			return (0);
		string = base + 1;
		while (*string != '\0')
		{
			if (*string == *base)
				return (0);
			string++;
		}
		(*size)++;
		base++;
	}
	if (*size <= 1)
		return (0);
	return (1);
}

static int	ft_get_digit(char cipher, char *base)
{
	int	digit;

	digit = 0;
	while (base[digit] != '\0')
	{
		if (base[digit] == cipher)
		{
			return (digit);
		}
		digit++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	resultado;
	int	digit;
	int	sign;
	int	size_base;

	resultado = 0;
	if (ft_check_base(base, &size_base) == 0)
		return (0);
	sign = ft_manage_sign(&str);
	while (*str != '\0')
	{
		digit = ft_get_digit(*str, base);
		if (digit >= 0)
			resultado = resultado * size_base + digit;
		else
			return (sign * resultado);
		str++;
	}
	return (sign * resultado);
}
