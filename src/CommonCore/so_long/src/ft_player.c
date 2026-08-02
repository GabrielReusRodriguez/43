/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:27:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 17:58:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_player.h"

t_player	ft_player_new(void)
{
	t_player	player;

	player.position.x = -1;
	player.position.y = -1;
	return (player);
}

void	ft_player_destroy(t_player *player)
{
	(void)player;
}
