/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:48:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/02 22:54:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map_bonus.h"
#include "ft_sprites_bonus.h"
#include "libft.h"

void	ft_sprite_destroy(void	*spr)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)spr;
	if (sprite->mlx_img != NULL)
		mlx_destroy_image(sprite->mlx_ptr, sprite->mlx_img);
	free (sprite);
}

t_sprite	*ft_sprite_load(t_mlx *mlx, char *path, unsigned char type, \
				unsigned char status)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->path = path;
	sprite->type = type;
	sprite->status = status;
	sprite->mlx_ptr = mlx->mlx_ptr;
	sprite->mlx_img = ft_mlx_load_sprite(mlx, sprite->path, &sprite->width, \
			&sprite->heigh);
	if (sprite->mlx_img == NULL)
	{
		ft_sprite_destroy(sprite);
		return (NULL);
	}
	return (sprite);
}

t_sprite	*ft_sprite_create_tile_0(t_mlx *mlx, const char *path, \
				t_list	**tile_list, int type)
{
	t_sprite	*sprite;
	t_list		*sprite_node;

	sprite = ft_sprite_load(mlx, (char *)path, type, 0);
	if (sprite == NULL)
	{
		ft_lstclear(tile_list, &ft_sprite_destroy);
		free(*tile_list);
		return (NULL);
	}
	sprite_node = ft_lstnew(sprite);
	if (sprite_node == NULL)
	{
		ft_lstclear(tile_list, &ft_sprite_destroy);
		ft_sprite_destroy(sprite);
		free(*tile_list);
		return (NULL);
	}
	ft_lstadd_front(tile_list, sprite_node);
	return (sprite);
}

t_sprite	*ft_sprite_create_tile_1(t_mlx *mlx, const char *path, \
				t_list	**tile_list, int type)
{
	t_sprite	*sprite;
	t_list		*sprite_node;

	sprite = ft_sprite_load(mlx, (char *)path, type, 1);
	if (sprite == NULL)
	{
		ft_lstclear(tile_list, &ft_sprite_destroy);
		free(*tile_list);
		return (NULL);
	}
	sprite_node = ft_lstnew(sprite);
	if (sprite_node == NULL)
	{
		ft_lstclear(tile_list, &ft_sprite_destroy);
		ft_sprite_destroy(sprite);
		free(*tile_list);
		return (NULL);
	}
	ft_lstadd_front(tile_list, sprite_node);
	return (sprite);
}

void	*ft_sprite_load_all(t_mlx *mlx)
{
	t_list		*lst_sprites;

	lst_sprites = NULL;
	if (ft_sprite_create_tile_0(mlx, "./sprites/grass.xpm", &lst_sprites, \
			EMPTY) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_0(mlx, "./sprites/wall.xpm", &lst_sprites, \
			WALL) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_0(mlx, "./sprites/coin_1.xpm", &lst_sprites, \
			COIN) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_0(mlx, "./sprites/PJ_right.xpm", &lst_sprites, \
			PLAYER) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_0(mlx, "./sprites/exit_closed.xpm", &lst_sprites, \
			EXIT) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_0(mlx, "./sprites/enemy.xpm", &lst_sprites, \
			ENEMY) == NULL)
		return (NULL);
	if (ft_sprite_create_tile_1(mlx, "./sprites/enemy2.xpm", &lst_sprites, \
			ENEMY) == NULL)
		return (NULL);
	return (lst_sprites);
}
