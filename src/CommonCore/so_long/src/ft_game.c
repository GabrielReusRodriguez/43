/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/05 18:15:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_game.h"
#include "ft_map.h"
#include "ft_sprites.h"
#include "ft_geometry2d.h"
#include "libft.h"

t_game	ft_game_new(void)
{
	t_game	game;

	game.score = 0;
	game.map = ft_map_new();
	game.loaded_sprites = NULL;
	game.mlx = ft_mlx_new();
	game.player = ft_player_new();
	game.exit = ft_exit_new();
	return (game);
}

void	ft_game_destroy(t_game *game)
{
	ft_player_destroy(&game->player);
	ft_lstclear(&game->loaded_sprites, &ft_sprite_destroy);
	ft_map_destroy(game->map);
	ft_mlx_destroy(&game->mlx);
}

void	ft_game_draw_map(t_game *game)
{
	t_sprite	*sprite;
	size_t		i;
	size_t		j;

	j = 0;
	while (game->map->ber_map[j] != NULL)
	{
		i = 0;
		while (i < game->map->width)
		{
			sprite = ft_game_get_loaded_sprite(game, game->map->ber_map[j][i] \
				, 0);
			if (sprite == NULL)
			{
				ft_game_destroy(game);
				exit(EXIT_FAILURE);
			}
			ft_mlx_draw_sprite(&game->mlx, sprite, i * 32, j * 32);
			i++;
		}
		j++;
	}
}

t_sprite	*ft_game_get_loaded_sprite(t_game *game, int type, int status)
{
	t_sprite	*sprite;
	t_list		*node;

	sprite = NULL;
	node = game->loaded_sprites;
	while (node != NULL)
	{
		sprite = (t_sprite *)node->content;
		if (sprite->type == type && sprite->status == status)
			return (sprite);
		node = node->next;
	}
	return (sprite);
}
