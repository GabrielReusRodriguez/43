/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:16:16 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/06 15:46:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE_BOARD 10
#define NO_PIECE -1

/*
https://rosettacode.org/wiki/N-queens_problem#C
*/

static void	ft_init_board(int	*board)
{
	unsigned int	i;

	i = 0;
	while (i < SIZE_BOARD)
	{
		board[i] = NO_PIECE;
		i++;
	}
}

static void	print_board(int	*board)
{
	unsigned int	i;
	char			digit;

	i = 0;
	while (i < SIZE_BOARD)
	{
		digit = '0' + board[i];
		write(1, &digit, 1);
		i++;
	}
	write(1, "\n", 1);
}

static int	ft_is_valid_place(int *board, int row, int column)
{
	int	j;

	j = 0;
	while (j < column)
	{
		if (board[j] != NO_PIECE)
		{
			if (board[j] == row)
				return (0);
			else
				if (board[j] - row == column - j || row - board[j] == column - j
					|| column + row == board[j] + j)
					return (0);
		}
		j++;
	}
	return (1);
}

static int	ft_new_queen(int *board, int column, int n)
{
	int	row;
	int	total;

	row = 0;
	total = 0;
	if (column == n)
	{
		print_board(board);
		return (1);
	}
	while (row < n)
	{
		if (ft_is_valid_place(board, row, column) == 1)
		{
			board[column] = row;
			total = total + ft_new_queen(board, column + 1, n);
		}
		row++;
	}
	return (total);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE_BOARD];
	int	col;
	int	solutions;

	ft_init_board(board);
	col = 0;
	solutions = 0;
	solutions = solutions + ft_new_queen(board, col, SIZE_BOARD);
	return (solutions);
}
