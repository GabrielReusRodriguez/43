/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:33 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 17:39:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_buffer_clear(void *buffer, int size)
{
	int				i;
	unsigned char	*u_buffer;

	i = 0;
	u_buffer = (unsigned char *)buffer;
	while (i < size)
	{
		u_buffer[i] = '\0';
		i++;
	}
}
