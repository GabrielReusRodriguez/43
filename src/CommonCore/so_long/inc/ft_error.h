/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:49:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/25 22:30:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <errno.h>
# include "ft_game.h"

void	ft_error_print_str(const char *str_error);
void	ft_error_print_errno(void);
void	ft_error_print_code(int err_code);
void	ft_error_exit_with_msg(t_game *game, const char	*str_error);
void	ft_error_exit(t_game *game);

#endif