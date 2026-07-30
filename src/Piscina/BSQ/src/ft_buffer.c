/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_clear_buffer(void *buffer, unsigned int size)
{
	unsigned int     i;
	char             *buf;

	i = 0;
	buf = (char *)buffer;
	while (i < size)
	{
		buf[i] = '\0';
		i++;
	}
}