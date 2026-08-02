/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:15:55 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 18:00:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mlx_wrapper.h"
#include "ft_config.h"

t_mlx	ft_mlx_new(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.heigh = 0;
	mlx.width = 0;
	return (mlx);
}

void	*ft_mlx_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	return (mlx->mlx_ptr);
}

void	*ft_mlx_create_window(t_mlx *mlx, size_t width, size_t heigh)
{
	mlx->heigh = heigh;
	mlx->width = width;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width * SPRITE_WIDTH, \
					mlx->heigh * SPRITE_HEIGH, WINDOW_NAME);
	return (mlx->win_ptr);
}
