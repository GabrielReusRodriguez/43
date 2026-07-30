/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:42:35 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/10 18:17:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

static void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr < 10)
	{
		digit = '0' + nbr;
		write(1, &digit, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == NULL)
		return ;
	while (par->str != NULL)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		ft_putstr(par->copy);
		par++;
	}
}
