/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:28:08 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/24 20:28:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_NUM_DIGITS 10

typedef struct s_number{
	char	number[MAX_NUM_DIGITS];
	int		overflow;
}	t_number;

static void	ft_init_number(t_number *buffer, int num_digits, int *posible)
{
	int	i;

	i = 0;
	while (i < num_digits)
	{
		buffer->number[i] = '0' + i;
		i++;
	}
	posible[0] = 0;
	posible[1] = 10;
	posible[2] = 45;
	posible[3] = 120;
	posible[4] = 210;
	posible[5] = 252;
	posible[6] = 210;
	posible[7] = 120;
	posible[8] = 45;
	posible[9] = 10;
	posible[10] = 1;
	buffer->overflow = 0;
}

static int	ft_check_number(t_number nb, int num_digits)
{
	int	i;

	i = 0;
	while (i < num_digits - 1)
	{
		if (nb.number[i] >= nb.number[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_print_number(t_number nb, int max_num_digits)
{
	int	i;

	i = 0;
	while (i < max_num_digits)
	{
		write(1, &nb.number[i], 1);
		i++;
	}
}

static void	ft_get_next_number(t_number *nb, int max, int *posible, int found)
{
	int	i;

	if (found >= posible[max])
	{
		nb->overflow = 1;
		return ;
	}
	i = max -1;
	nb->number[i] = nb->number[i] + 1;
	while (i >= 0)
	{
		if (nb->number[i] > '9')
		{
			nb->number[i] = '0';
			nb->overflow = 1;
		}
		else
		{
			nb->number[i] = nb->number[i] + nb->overflow;
			nb->overflow = 0;
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	t_number	number;
	int			i;
	int			first_print;
	int			num_posibles[MAX_NUM_DIGITS + 1];

	if (n <= 0)
		n = 1;
	if (n > MAX_NUM_DIGITS)
		n = MAX_NUM_DIGITS;
	i = 0;
	first_print = 1;
	ft_init_number(&number, n, num_posibles);
	while (number.overflow == 0)
	{
		if (ft_check_number(number, n) == 1)
		{
			if (first_print == 0)
				write(1, ", ", 2);
			ft_print_number(number, n);
			first_print = 0;
			i++;
		}
		ft_get_next_number(&number, n, num_posibles, i);
	}
}
