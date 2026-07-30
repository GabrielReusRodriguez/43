/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:43 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 16:54:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static unsigned int	ft_get_ptr_size(char *src)
{
	unsigned int	ptr_size;

	ptr_size = 0;
	while (src[ptr_size] != '\0')
		ptr_size++;
	return (ptr_size);
}

static void	ft_copy_string(char *dst, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && *src != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	if (src == NULL)
		return (0);
	if (size == 0)
	{
		return (ft_get_ptr_size(src));
	}
	ft_copy_string(dest, src, size);
	return (ft_get_ptr_size(src));
}
