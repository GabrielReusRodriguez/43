/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:36:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 17:59:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pathfinding.h"
#include "ft_bfs.h"
#include "ft_error.h"

t_bool	ft_path_exists(t_game	*game)
{
	t_map		*map;

	map = game->map;
	if (map->ber_map == NULL)
	{
		ft_error_print_str("Error\nError loading map");
		return (FALSE);
	}
	if (ft_bfs(game) == FALSE)
	{
		ft_error_print_str("Error\nThere is NOT a path from start to exit.");
		return (FALSE);
	}
	return (TRUE);
}
