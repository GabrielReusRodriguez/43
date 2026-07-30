/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:31:23 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/29 18:14:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	char	*destination;
	char	*source;
	int		i;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	destination = dest;
	source = src;
	i = 0;
	while (i < n && *source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
		i++;
	}
	while (i < n)
	{
		*destination = '\0';
		destination++;
		i++;
	}
	return (dest);
}
