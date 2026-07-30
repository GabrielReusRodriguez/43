/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:42:19 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/29 17:45:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*destination;
	char	*source;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	destination = dest;
	source = src;
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = *source;
	return (dest);
}
