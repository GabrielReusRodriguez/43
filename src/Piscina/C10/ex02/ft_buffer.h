/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:07:14 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 13:08:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

void	ft_clean_buffer(void *buffer, unsigned int size_bytes);
void	ft_shift_buffer(char *buffer, char character, unsigned int num_bytes);

#endif
