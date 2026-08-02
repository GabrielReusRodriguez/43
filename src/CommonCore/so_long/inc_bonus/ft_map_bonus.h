/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:25 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:51:23 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_BONUS_H
# define FT_MAP_BONUS_H

# include "ft_utils_bonus.h"

# define WALL	'1'
# define EMPTY	'0'
# define PLAYER	'P'
# define COIN	'C'
# define EXIT	'E'
# define ENEMY	'X'

/* Forward declaration to avoid circular includes*/
typedef struct s_game	t_game;

typedef struct s_map
{
	char			**ber_map;
	unsigned int	width;
	unsigned int	height;
	unsigned int	num_coins;
}	t_map;

t_map	*ft_map_new(void);
void	ft_map_load(t_game *game, const char *map_name);
void	ft_map_destroy(t_map *map);
char	*ft_read_map_file(const char *map_file);

/*
	Validations
*/
t_bool	ft_map_is_rectangular(t_map *map);
t_bool	ft_map_is_min_size(t_map *map);
t_bool	ft_map_has_all_elements(t_map *map);
t_bool	ft_map_is_closed(t_map *map);
t_bool	ft_map_has_valid_path(t_map *map);
t_bool	ft_map_validation(t_game *game);

#endif
