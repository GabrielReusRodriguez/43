/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:14:07 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:36:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "./ft_geometry.h"

typedef struct s_map
{
	char			**map;
	unsigned int	rows;
	unsigned int	lines;
	char			empty;
	char			obstacle;
	char			full;
}	t_map;


//typedef char **	t_map;

t_map		*ft_load_map(char *file);
t_rectangle	*ft_get_next_rectangle(t_map map, t_point initial);
void	ft_print_map(t_map *map);
void	ft_free_map(t_map *map);

#endif
