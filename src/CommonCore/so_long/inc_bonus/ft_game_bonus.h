/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:05:02 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:50:59 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_BONUS_H
# define FT_GAME_BONUS_H

# include "ft_player_bonus.h"
# include "ft_exit_bonus.h"
# include "ft_map_bonus.h" 
# include "ft_mlx_wrapper_bonus.h"
# include "ft_sprites_bonus.h"
# include "libft.h"

typedef struct s_game
{
	unsigned int	score;
	t_player		player;
	t_exit			exit;
	t_map			*map;
	t_mlx			mlx;
	t_list			*loaded_sprites;
	unsigned char	animation_status;
}	t_game;

t_game		ft_game_new(void);
void		ft_game_draw_map(t_game	*game);
void		ft_game_destroy(t_game *game);
t_sprite	*ft_game_get_loaded_sprite(t_game *game, int type, int status);
void		ft_game_get_positions(t_game *game);
void		ft_game_move_player(t_game *game, int direction);
void		ft_game_print_score(t_game	*game);

#endif