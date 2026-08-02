/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:58:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "libft.h"

t_bool	ft_map_is_rectangular(t_map *map)
{
	size_t	i;
	char	*line;

	map->width = ft_strlen(map->ber_map[0]);
	i = 0;
	line = map->ber_map[0];
	while (line != NULL)
	{
		if (map->width != ft_strlen(line))
			return (FALSE);
		i++;
		line = map->ber_map[i];
	}
	map->height = i;
	return (TRUE);
}

t_bool	ft_map_is_min_size(t_map *map)
{
	if (map->height < 3 || map->width < 3)
		return (FALSE);
	return (TRUE);
}

static t_bool	ft_map_is_valid_type(char type, size_t *num_player, \
		size_t *num_exit, unsigned int *num_coins)
{
	if (type == PLAYER)
	{
		*num_player = *num_player + 1;
		return (TRUE);
	}
	if (type == EXIT)
	{
		*num_exit = *num_exit + 1;
		return (TRUE);
	}
	if (type == COIN)
	{
		*num_coins = *num_coins + 1;
		return (TRUE);
	}
	if (type == EMPTY)
		return (TRUE);
	if (type == WALL)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_map_has_all_elements(t_map *map)
{
	size_t	i;
	size_t	num_player;
	size_t	j;
	size_t	num_exit;

	i = 0;
	num_player = 0;
	map->num_coins = 0;
	num_exit = 0;
	while (map->ber_map[i] != NULL)
	{
		j = 0;
		while (map->ber_map[i][j] != '\0' && map->ber_map[i][j] != '\n')
		{
			if (ft_map_is_valid_type(map->ber_map[i][j], &num_player, \
					&num_exit, &map->num_coins) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	if (num_player != 1 || map->num_coins == 0 || num_exit != 1)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_map_is_closed(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->ber_map[i] != NULL)
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->ber_map[i][j] != WALL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			j = map->width -1;
			if (map->ber_map[i][0] != WALL || map->ber_map[i][j] != WALL)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
