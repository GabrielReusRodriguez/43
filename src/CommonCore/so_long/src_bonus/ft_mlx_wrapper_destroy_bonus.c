/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper_destroy_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:19:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:32:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mlx_wrapper_bonus.h"

void	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_mlx_destroy_window(mlx);
	}
	if (mlx->mlx_ptr != NULL)
	{
		ft_mlx_destroy_display(mlx);
	}
}

/*
the Mlx destroy window function DOES a free of win_ptr so 
it is NOT necessary to free again
*/
void	ft_mlx_destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
}

#ifdef __APPLE__

void	ft_mlx_destroy_display(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
}

#else

void	ft_mlx_destroy_display(t_mlx *mlx)
{
	if (mlx->mlx_ptr == NULL)
		return ;
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
}

#endif

void	ft_mlx_free(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
	{
		free (mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	if (mlx->mlx_ptr != NULL)
	{
		free (mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}
