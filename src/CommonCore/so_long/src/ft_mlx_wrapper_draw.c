/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:24:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/05 18:15:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprites.h"
#include "ft_mlx_wrapper.h"

void	ft_mlx_draw_sprite(t_mlx *mlx, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, sprite->mlx_img, \
			x, y);
}
