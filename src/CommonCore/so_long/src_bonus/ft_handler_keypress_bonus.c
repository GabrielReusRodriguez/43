/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_keypress_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:06:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:32:03 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_keycodes_bonus.h"
#include "ft_event_handlers_bonus.h"

int	ft_handler_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_CODE_ESC)
		ft_handler_destroy(game);
	if (keycode == KEY_CODE_A)
		ft_game_move_player(game, MOVE_LEFT);
	if (keycode == KEY_CODE_D)
		ft_game_move_player(game, MOVE_RIGHT);
	if (keycode == KEY_CODE_W)
		ft_game_move_player(game, MOVE_UP);
	if (keycode == KEY_CODE_S)
		ft_game_move_player(game, MOVE_DOWN);
	return (0);
}
