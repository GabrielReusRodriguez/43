/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:25:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/25 22:44:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENTS_H
# define FT_EVENTS_H

enum e_mlx_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define KEY_PRESS_EVENT ON_KEYDOWN

# ifdef __APPLE__
#  define KEY_PRESS_MASK 0
#  define DESTROY_MASK 0
# else
#  define KEY_PRESS_MASK 1
#  define DESTROY_MASK 131072
# endif

#endif
