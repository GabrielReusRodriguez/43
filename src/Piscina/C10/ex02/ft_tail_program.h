/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_program.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:08:56 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:04:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_PROGRAM_H
# define FT_TAIL_PROGRAM_H

void	ft_append_char(char *buffer, char character, unsigned int num_bytes, \
	unsigned int *position);
char	*ft_parse_file(int fd, unsigned int num_bytes);
void	ft_tail_program(char *file, unsigned int num_bytes);

#endif
