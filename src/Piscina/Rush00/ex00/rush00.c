/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:19:28 by cgomez-z          #+#    #+#             */
/*   Updated: 2026/07/30 15:45:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

static void	ft_print_line(int x, char left, char mid, char right)
{
	int	col;

	if (x <= 0)
		return ;
	col = 1;
	ft_putchar(left);
	while (col < x - 1)
	{
		ft_putchar(mid);
		col++;
	}
	if (x > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	ft_print_line(x, 'A', 'B', 'C');
	while (row < y - 1)
	{
		ft_print_line(x, 'B', ' ', 'B');
		row++;
	}
	if (y > 1)
		ft_print_line(x, 'A', 'B', 'C');
}
