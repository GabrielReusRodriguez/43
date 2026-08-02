/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_draw_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:24:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:52:56 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprites_bonus.h"
#include "ft_mlx_wrapper_bonus.h"

void	ft_mlx_draw_sprite(t_mlx *mlx, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, sprite->mlx_img, \
			x, y);
}

void	ft_mlx_putstr(t_mlx *mlx, int x, int y, char *string)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, MLX_DEFAULT_TEXT_COLOR, \
			string);
}
