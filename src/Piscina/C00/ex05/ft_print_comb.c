/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:27:00 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 17:59:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_number(char *digit1, char *digit2, \
		char *digit3, unsigned int is_first)
{
	char	coma;
	char	space;

	coma = ',';
	space = ' ';
	if (is_first == 0)
	{
		write(1, &coma, 1);
		write(1, &space, 1);
	}
	write(1, digit1, 1);
	write(1, digit2, 1);
	write(1, digit3, 1);
}

void	ft_print_comb(void)
{
	char			first;
	char			second;
	char			third;
	unsigned int	is_first;

	first = '0';
	is_first = 1;
	while (first <= '9')
	{
		second = first + 1;
		while (second <= '9')
		{
			third = second +1;
			while (third <= '9')
			{
				write_number (&first, &second, &third, is_first);
				is_first = 0;
				third = third + 1;
			}
			second = second + 1;
		}
		first = first + 1;
	}
}
