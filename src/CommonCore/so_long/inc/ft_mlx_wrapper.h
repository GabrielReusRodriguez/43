/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_wrapper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:12:03 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 17:51:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WRAPPER_H
# define FT_MLX_WRAPPER_H

# include <stddef.h>
# include "mlx.h"

/* 
	Forward declaration to avoid circular includes
*/
typedef struct s_game	t_game;
typedef struct s_sprite	t_sprite;

# define MLX_DEFAULT_MASK 0

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	width;
	size_t	heigh;
}	t_mlx;

t_mlx	ft_mlx_new(void);
void	*ft_mlx_init(t_mlx *mlx);
void	ft_mlx_free(t_mlx *mlx);

void	ft_mlx_destroy(t_mlx *mlx);
void	*ft_mlx_create_window(t_mlx *mlx, size_t width, size_t heigh);
void	ft_mlx_destroy_window(t_mlx *mlx);
void	ft_mlx_destroy_display(t_mlx *mlx);

void	ft_mlx_hook_functions(t_game *game);

void	*ft_mlx_load_sprite(t_mlx *mlx, const char *path, int *width, \
				int *height);
void	ft_mlx_draw_sprite(t_mlx *mlx, t_sprite *sprite, int x, int y);

#endif
