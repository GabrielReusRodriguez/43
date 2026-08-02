/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:59:33 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 19:20:27 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_game.h"
#include "ft_map.h"
#include "ft_get_next_line.h"
#include "libft.h"
#include "ft_error.h"

static void	ft_map_print_error_msg(t_game *game, const char *msg)
{
	ft_error_print_str(msg);
	ft_game_destroy(game);
	exit(EXIT_FAILURE);
}

static size_t	ft_map_get_heigh(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->ber_map[i] != NULL)
		i++;
	return (i);
}

void	ft_map_load(t_game	*game, const char *map_file)
{
	char	*char_map;

	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
	{
		ft_error_print_code(ENOMEM);
		ft_game_destroy(game);
		exit(EXIT_FAILURE);
	}
	game->map->ber_map = NULL;
	char_map = ft_read_map_file(map_file);
	if (char_map == NULL)
		ft_map_print_error_msg(game, "Error\n Error reading map file");
	game->map->ber_map = ft_split(char_map, '\n');
	if (game->map->ber_map == NULL)
		ft_map_print_error_msg(game, "Error\n Error reading map file");
	game->map->width = ft_strlen(game->map->ber_map[0]);
	game->map->height = ft_map_get_heigh(game->map);
	free (char_map);
}

/*
static void ft_map_debug(t_map	*map)
{
	printf("heigh %d\n",map->height);
	printf("width %d\n",map->width);
}
*/
void	ft_map_destroy(t_map *map)
{
	size_t	i;

	if (map != NULL)
	{
		if (map->ber_map != NULL)
		{
			i = 0;
			while (i < map->height)
			{
				free (map->ber_map[i]);
				i++;
			}
			free (map->ber_map);
		}
		free(map);
	}
}

t_map	*ft_map_new(void)
{
	return (NULL);
}
