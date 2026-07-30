/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:34:35 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/30 15:57:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_positive(int nb)
{
	char	digit;

	if (nb < 10)
	{
		digit = '0' + nb;
		write(1, &digit, 1);
	}
	else
	{
		ft_putnbr_positive(nb / 10);
		ft_putnbr_positive(nb % 10);
	}
}

static void	ft_putnbr_negative(int nb)
{
	char	digit;

	if (nb > -10)
	{
		digit = '0' - nb;
		write(1, &digit, 1);
	}
	else
	{
		ft_putnbr_negative(nb / 10);
		ft_putnbr_negative(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	char	sign;

	sign = '-';
	if (nb < 0)
	{
		write(1, &sign, 1);
		ft_putnbr_negative(nb);
	}
	else
	{
		ft_putnbr_positive(nb);
	}
}
