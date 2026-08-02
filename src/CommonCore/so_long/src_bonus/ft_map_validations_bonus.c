/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:58:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:32:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_game_bonus.h"
#include "ft_error_bonus.h"

static t_bool	ft_map_validation_format(t_map *map)
{
	if (ft_map_is_rectangular(map) == FALSE)
	{
		ft_error_print_str("Error\nMap is NOT squared / rectangular");
		return (FALSE);
	}
	if (ft_map_is_min_size(map) == FALSE)
	{
		ft_error_print_str("Error\nMap has NOT the minimum sizes");
		return (FALSE);
	}
	if (ft_map_has_all_elements(map) == FALSE)
	{
		ft_error_print_str("Error\nMap has NOT valid format");
		return (FALSE);
	}
	if (ft_map_is_closed(map) == FALSE)
	{
		ft_error_print_str("Error\nMap is NOT closed");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_map_validation(t_game *game)
{
	t_map		*map;

	map = game->map;
	if (map->ber_map == NULL)
	{
		ft_error_print_str("Error\nError loading map");
		return (FALSE);
	}
	if (ft_map_validation_format(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
