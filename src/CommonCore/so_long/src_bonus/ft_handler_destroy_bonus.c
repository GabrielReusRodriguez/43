/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_destroy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:38:07 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_game_bonus.h"

int	ft_handler_destroy(t_game *game)
{
	ft_game_destroy(game);
	exit(EXIT_SUCCESS);
}
