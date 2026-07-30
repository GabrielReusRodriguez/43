/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void    ft_putline(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr < 10)
	{
		digit = '0' + nbr;
		write (1, &digit, 1);
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}