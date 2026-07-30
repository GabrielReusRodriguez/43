/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:01:59 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 14:20:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putline(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}
/*
char	*ft_strcat(char *dst, char *src)
{
	char	*ret;
	char	*source;
	char	*destination;
	int		src_size;
	int		dst_size;

	destination = dest;
	source = src;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);


	return (msg); 
}*/
