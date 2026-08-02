/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:05:02 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:34:14 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_player.h"
# include "ft_exit.h"
# include "ft_map.h" 
# include "ft_mlx_wrapper.h"
# include "ft_sprites.h"
# include "libft.h"

typedef struct s_game
{
	unsigned int	score;
	t_player		player;
	t_exit			exit;
	t_map			*map;
	t_mlx			mlx;
	t_list			*loaded_sprites;
}	t_game;

t_game		ft_game_new(void);
void		ft_game_draw_map(t_game	*game);
void		ft_game_destroy(t_game *game);
t_sprite	*ft_game_get_loaded_sprite(t_game *game, int type, int status);
void		ft_game_get_positions(t_game *game);
void		ft_game_move_player(t_game *game, int direction);

#endif