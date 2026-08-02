/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:47:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "ft_error_bonus.h"
#include "libft.h"

void	ft_error_print_str(const char *str_error)
{
	ft_putendl_fd((char *)str_error, STDERR_FILENO);
}

void	ft_error_print_errno(void)
{
	perror("Error");
}

void	ft_error_print_code(int err_code)
{
	char	*str_error;

	str_error = strerror(err_code);
	ft_putendl_fd(str_error, STDERR_FILENO);
}

void	ft_error_exit_with_msg(t_game *game, const char	*str_error)
{
	ft_error_print_str(str_error);
	if (game != NULL)
		ft_game_destroy(game);
	exit(EXIT_FAILURE);
}

void	ft_error_exit(t_game *game)
{
	if (game != NULL)
		ft_game_destroy(game);
	exit(EXIT_FAILURE);
}
