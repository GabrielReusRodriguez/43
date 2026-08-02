/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:27:40 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 18:01:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx_wrapper.h"

void	*ft_mlx_load_sprite(t_mlx *mlx, const char *path, int *width, \
				int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, (char *)path, width, height);
	return (img);
}
