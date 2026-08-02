/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_hooks_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:43:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:33:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game_bonus.h"
#include "ft_event_handlers_bonus.h"
#include "ft_events_bonus.h"

void	ft_mlx_hook_functions(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK, \
				&ft_handler_keypress, game);
	mlx_hook(game->mlx.win_ptr, ON_DESTROY, DESTROY_MASK, \
				&ft_handler_destroy, game);
	mlx_loop_hook(game->mlx.mlx_ptr, &ft_handler_render, game);
}
