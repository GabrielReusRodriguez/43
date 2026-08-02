/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycodes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:19 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/01 17:44:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEYCODES_H
# define FT_KEYCODES_H

# ifdef __APPLE__
#  define KEY_CODE_ESC 53
#  define KEY_CODE_A 0
#  define KEY_CODE_S 1
#  define KEY_CODE_D 2
#  define KEY_CODE_W 13
# else
#  define KEY_CODE_ESC 65307
#  define KEY_CODE_A 97
#  define KEY_CODE_S 115
#  define KEY_CODE_D 100
#  define KEY_CODE_W 119
# endif

#endif
