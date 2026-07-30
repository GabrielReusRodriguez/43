/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:37:22 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FIRST_PRINTABLE_CHAR 32
#define LAST_PRINTABLE_CHAR 126

static int	ft_is_printable(char c)
{
	if (c >= FIRST_PRINTABLE_CHAR && c <= LAST_PRINTABLE_CHAR)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static char	ft_dec_2_hex(unsigned int nbr)
{
	int	difference;

	if (nbr < 10)
	{
		return ('0' + nbr);
	}
	else
	{
		difference = nbr - 10;
		return ('a' + difference);
	}
}

static void	ft_write_no_printable(unsigned char c)
{
	char			slash;
	unsigned char	div;
	unsigned int	total;
	char			hex_char;

	slash = '\\';
	write(1, &slash, 1);
	div = 1;
	total = c;
	div = total / 16;
	total = total % 16;
	hex_char = ft_dec_2_hex(div);
	write(1, &hex_char, 1);
	hex_char = ft_dec_2_hex(total);
	write(1, &hex_char, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*string;

	if (str == NULL)
	{
		return ;
	}
	string = str;
	while (*string != '\0')
	{
		if (ft_is_printable(*string) == 0)
		{
			ft_write_no_printable((unsigned char)*string);
		}
		else
		{
			write(1, string, 1);
		}
		string++;
	}
}
