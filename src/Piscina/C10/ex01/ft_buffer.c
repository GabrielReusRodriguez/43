/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:30 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 13:16:03 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_clean_buffer(void *buffer, unsigned int size_bytes)
{
	unsigned int	i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char *)buffer;
	while (i < size_bytes)
	{
		buf[i] = '\0';
		i++;
	}
}
