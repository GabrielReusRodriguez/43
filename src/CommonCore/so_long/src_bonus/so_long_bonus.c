/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:14:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:59:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx_wrapper_bonus.h"
#include "ft_game_bonus.h"
#include "ft_error_bonus.h"
#include "ft_pathfinding_bonus.h"

/*
MAC maximum resolution = 5120 x 2880 Retina.

Minbbnilibx in MAC is better to validate
all things not related with minilibx before load it to avoid leaks.

The exception are sprites because we need minilibx initiated.
so the order is...
	1. Validate args of main.
	2. Create game structure.
	3. Load the map.
	4. Validate the map is correct.
	5. We get the exit and player positions in map
	6. We look for a possible path between start en exit.
	7. We init the minilibx.
	8. We create the window.
	9. We append the hook functions.
	10. We load sprites in the CACHE list. To do this, we need minilibx loaded.
	11. We draw the first frame of game.
	12. We call the loop. 
We do NOT call game destroy after mlx_loop because we call it in the destroy 
	minilibx event.
*/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_exit_with_msg(NULL, "Error\n You did not pass 2 args");
	game = ft_game_new();
	ft_map_load(&game, argv[1]);
	if (ft_map_validation(&game) == FALSE)
		ft_error_exit(&game);
	ft_game_get_positions(&game);
	if (ft_path_exists(&game) == FALSE)
		ft_error_exit(&game);
	if (ft_mlx_init(&game.mlx) == NULL)
		ft_error_exit_with_msg(&game, "Error\n Error mlx init");
	if (ft_mlx_create_window(&game.mlx, game.map->width, \
			game.map->height) == NULL)
		ft_error_exit_with_msg(&game, "Error\n Error mlx creating window");
	ft_mlx_hook_functions(&game);
	game.loaded_sprites = ft_sprite_load_all(&game.mlx);
	if (game.loaded_sprites == NULL)
		ft_error_exit_with_msg(&game, "Error\n Error loading sprites");
	ft_game_draw_map(&game);
	ft_game_print_score(&game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
