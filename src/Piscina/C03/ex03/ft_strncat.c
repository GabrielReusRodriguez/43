/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:44:22 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/30 17:07:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char				*source;
	char				*destiny;
	unsigned int		i;

	source = src;
	destiny = dest;
	i = 0;
	while (*destiny != '\0')
	{
		destiny++;
	}
	while (*source != '\0' && i < nb)
	{
		*destiny = *source;
		source++;
		destiny++;
		i++;
	}
	if (*destiny != '\0')
	{
		*destiny = '\0';
	}
	return (dest);
}
