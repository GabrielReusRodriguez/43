/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:30:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:34:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H

# include "ft_geometry2d.h"
# include "ft_sprites.h"

typedef struct s_player
{
	t_point2d		position;
}	t_player;

t_player	ft_player_new(void);
void		ft_player_destroy(t_player *player);

#endif