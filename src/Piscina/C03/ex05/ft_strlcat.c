/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:34:44 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 21:46:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static unsigned int	get_ptr_size(char *ptr)
{
	unsigned int	size;

	size = 0;
	while (*ptr != '\0')
	{
		size++;
		ptr++;
	}
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int dstsize)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	size;

	size_src = get_ptr_size(src);
	size_dest = get_ptr_size(dest);
	if (size_dest < dstsize)
		size = size_dest + size_src;
	else
		size = size_src + dstsize;
	while (size_dest + 1 < dstsize && *src != '\0')
	{
		dest[size_dest] = *src;
		size_dest++;
		src++;
	}
	if (size_dest < dstsize)
	{
		dest[size_dest] = '\0';
	}
	return (size);
}
