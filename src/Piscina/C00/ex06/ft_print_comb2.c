/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:27:34 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 20:11:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_number{
	char	digit1;
	char	digit2;
}	t_number;

static void	get_next_number(t_number *number)
{
	number->digit2 = number->digit2 + 1;
	if (number->digit2 > '9')
	{
		number->digit2 = '0';
		number->digit1 = number->digit1 + 1;
	}
}

static void	write_number(t_number *number)
{
	if (number->digit1 >= '0' && number->digit1 <= '9' && number->digit2 >= '0' \
	&& number->digit2 <= '9')
	{
		write(1, &(number->digit1), 1);
		write(1, &(number->digit2), 1);
	}
}

void	new_comb(t_number *first, t_number *second, unsigned int *is_first)
{
	char	coma;
	char	space;

	coma = ',';
	space = ' ';
	while (second->digit1 <= '9' && second->digit2 <= '9' && \
		!(second->digit1 == '9' && second->digit2 == '9'))
	{
		get_next_number (second);
		if (*is_first == 0)
		{
			write (1, &coma, 1);
			write (1, &space, 1);
		}
		*is_first = 0;
		write_number (first);
		write (1, &space, 1);
		write_number (second);
	}
}

void	ft_print_comb2(void)
{
	t_number		first;
	t_number		second;
	unsigned int	is_first;

	is_first = 1;
	first.digit1 = '0';
	first.digit2 = '0';
	while (first.digit1 <= '9' && first.digit2 <= '9')
	{
		second.digit1 = first.digit1;
		second.digit2 = first.digit2;
		new_comb (&first, &second, &is_first);
		get_next_number (&first);
	}
}
