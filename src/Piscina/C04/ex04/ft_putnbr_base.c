/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:57:15 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 20:50:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define LOW_PRINTABLE_CHAR 32
#define HIGH_PRINTABLE_CHAR 126

static unsigned int	ft_get_base(char *base)
{
	unsigned int	num_base;

	num_base = 0;
	while (*base != '\0')
	{
		num_base++;
		base++;
	}
	return (num_base);
}

static int	ft_manage_sign(int nb)
{
	int		sign;
	char	minus_sign;

	sign = 1;
	minus_sign = '-';
	if (nb < 0)
	{
		sign = -1;
		write(1, &minus_sign, 1);
	}
	return (sign);
}

static int	ft_check_base(char *base)
{
	unsigned int	size;
	char			*string;

	size = 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || *base == ' '
			|| !(*base >= LOW_PRINTABLE_CHAR && *base <= HIGH_PRINTABLE_CHAR))
		{
			return (0);
		}
		string = base;
		while (*string != '\0')
		{
			string++;
			if (*base == *string)
			{
				return (0);
			}
		}
		size++;
		base++;
	}
	return (size - 1);
}

static void	ft_putnbr_b(int nb, char	*base, int dec_base, int sign)
{
	char	digit;

	if (sign < 0)
	{
		if (nb > -dec_base)
		{
			digit = base[-nb];
			write(1, &digit, 1);
			return ;
		}
		ft_putnbr_b(nb / dec_base, base, dec_base, sign);
		ft_putnbr_b(nb % dec_base, base, dec_base, sign);
	}
	else
	{
		if (nb < dec_base)
		{
			digit = base[nb];
			write(1, &digit, 1);
			return ;
		}
		ft_putnbr_b(nb / dec_base, base, dec_base, sign);
		ft_putnbr_b(nb % dec_base, base, dec_base, sign);
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	int					sign;
	unsigned int		base_num;

	if (ft_check_base(base) <= 0)
	{
		return ;
	}
	sign = ft_manage_sign(nb);
	base_num = ft_get_base(base);
	ft_putnbr_b(nb, base, base_num, sign);
}
