/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 23:00:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_game_bonus.h"
#include "ft_map_bonus.h"
#include "ft_sprites_bonus.h"
#include "ft_geometry2d_bonus.h"
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
	game.animation_status = 0;
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
				, game->animation_status);
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
	if (type != ENEMY)
		status = 0;
	while (node != NULL)
	{
		sprite = (t_sprite *)node->content;
		if (sprite->type == type && sprite->status == status)
			return (sprite);
		node = node->next;
	}
	return (sprite);
}

void	ft_game_print_score(t_game	*game)
{
	char	*text;
	char	*str_score;

	str_score = ft_itoa(game->score);
	if (str_score == NULL)
	{
		ft_game_destroy(game);
		exit(EXIT_FAILURE);
	}
	text = ft_strjoin("MOVES: ", str_score);
	ft_mlx_putstr(&game->mlx, 10, 10, text);
	free(str_score);
	free(text);
}
