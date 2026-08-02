/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:16:06 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:16 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit_bonus.h"

t_exit	ft_exit_new(void)
{
	t_exit	exit;

	exit.position.x = -1;
	exit.position.y = -1;
	exit.active = FALSE;
	return (exit);
}
