/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:28:08 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/24 20:28:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_recursive(unsigned int nb)
{
	char	digit;

	if (nb < 10)
	{
		digit = '0' + nb;
		write(1, &digit, 1);
		return ;
	}
	ft_putnbr_recursive(nb / 10);
	ft_putnbr_recursive(nb % 10);
}

void	ft_putnbr(int nb)
{
	unsigned int	unbr;

	if (nb < 0)
	{
		write(1, "-", 1);
		unbr = -nb;
	}
	else
		unbr = nb;
	ft_putnbr_recursive(unbr);
}
