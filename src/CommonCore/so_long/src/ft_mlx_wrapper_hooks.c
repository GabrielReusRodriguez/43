/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_hooks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:43:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/05 18:15:02 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"
#include "ft_event_handlers.h"
#include "ft_events.h"

void	ft_mlx_hook_functions(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK, \
				&ft_handler_keypress, game);
	mlx_hook(game->mlx.win_ptr, ON_DESTROY, DESTROY_MASK, \
				&ft_handler_destroy, game);
	mlx_loop_hook(game->mlx.mlx_ptr, &ft_handler_render, game);
}
