/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:44:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:51:45 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRITES_BONUS_H
# define FT_SPRITES_BONUS_H

# include "ft_mlx_wrapper_bonus.h"

typedef struct s_sprite
{
	unsigned char	type;
	unsigned char	status;
	char			*path;
	int				width;
	int				heigh;
	void			*mlx_img;
	void			*mlx_ptr;
}	t_sprite;

t_sprite	*ft_sprite_load(t_mlx *mlx, char *path, unsigned char type, \
				unsigned char status);
void		ft_sprite_destroy(void	*sprite);
void		*ft_sprite_load_all(t_mlx *mlx);

#endif