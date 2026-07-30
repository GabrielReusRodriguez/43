/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:14:07 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:36:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIRST_LINE_H
# define FT_FIRST_LINE_H

# include "ft_map.h"

int     ft_parse_first_line(int fd, t_map *map);
int     ft_parse_num_lines(int fd, t_map *map);
int     ft_parse_char(int fd, char *character);


#endif
