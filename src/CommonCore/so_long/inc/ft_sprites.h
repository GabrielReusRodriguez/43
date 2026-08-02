/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:44:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:35:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRITES_H
# define FT_SPRITES_H

# include "ft_mlx_wrapper.h"

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