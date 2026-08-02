/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handlers_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:27:28 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:50:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_HANDLERS_BONUS_H
# define FT_EVENT_HANDLERS_BONUS_H

# include "ft_game_bonus.h"

int	ft_handler_no_event(void);
int	ft_handler_keypress(int keycode, t_game *game);
int	ft_handler_destroy(t_game *game);
int	ft_handler_render(void *param);

#endif