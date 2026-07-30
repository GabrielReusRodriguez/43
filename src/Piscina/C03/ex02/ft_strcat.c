/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:36:20 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/03 20:41:31 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcat(char *dest, char *src)
{
	char				*source;
	char				*destiny;

	source = src;
	destiny = dest;
	while (*destiny != '\0')
	{
		destiny++;
	}
	while (*source != '\0')
	{
		*destiny = *source;
		source++;
		destiny++;
	}
	*destiny = '\0';
	return (dest);
}
