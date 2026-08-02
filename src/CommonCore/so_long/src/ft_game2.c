/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:49:56 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_game.h"
#include "ft_map.h"
#include "ft_sprites.h"
#include "ft_geometry2d.h"
#include "libft.h"

void	ft_game_get_positions(t_game *game)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < game->map->height)
	{
		i = 0;
		while (i < game->map->width)
		{
			if (game->map->ber_map[j][i] == EXIT)
				game->exit.position = ft_point2d_new(i, j);
			if (game->map->ber_map[j][i] == PLAYER)
				game->player.position = ft_point2d_new(i, j);
			if (game->player.position.x >= 0 && game->exit.position.x >= 0)
				return ;
			i++;
		}
		j++;
	}
}

static t_bool	ft_game_check_movement(t_game	*game, t_point2d	position)
{
	char	cell_type;

	if (position.x < 0 || position.x > (int)game->map->width)
		return (FALSE);
	if (position.y < 0 || position.y > (int)game->map->height)
		return (FALSE);
	cell_type = game->map->ber_map[position.y][position.x];
	if (cell_type == WALL)
		return (FALSE);
	if (cell_type == EXIT && game->exit.active == FALSE)
		return (FALSE);
	return (TRUE);
}

void	ft_game_print_score(t_game	*game)
{
	char	*str_score;

	str_score = ft_itoa(game->score);
	if (str_score == NULL)
	{
		ft_game_destroy(game);
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd(str_score, STDOUT_FILENO);
	free(str_score);
}

void	ft_game_move(t_game	*game, t_point2d position)
{
	if (game->map->ber_map[position.y][position.x] == EXIT)
	{
		if (game->exit.active == TRUE)
		{
			ft_putendl_fd("You WON!", STDOUT_FILENO);
			ft_game_destroy(game);
			exit(EXIT_SUCCESS);
		}
		return ;
	}
	if (game->map->ber_map[position.y][position.x] == COIN)
	{
		game->map->num_coins--;
		if (game->map->num_coins == 0)
			game->exit.active = TRUE;
	}
	game->score++;
	game->map->ber_map[game->player.position.y][game->player.position.x] \
			= EMPTY;
	game->player.position = position;
	game->map->ber_map[game->player.position.y][game->player.position.x] \
			= PLAYER;
}

void	ft_game_move_player(t_game *game, int direction)
{
	t_point2d	player_position;

	player_position = game->player.position;
	if (direction == MOVE_DOWN)
		player_position.y++;
	if (direction == MOVE_UP)
		player_position.y--;
	if (direction == MOVE_RIGHT)
		player_position.x++;
	if (direction == MOVE_LEFT)
		player_position.x--;
	if (ft_game_check_movement(game, player_position) == FALSE)
		return ;
	ft_game_move(game, player_position);
	ft_game_draw_map(game);
	ft_game_print_score(game);
}
