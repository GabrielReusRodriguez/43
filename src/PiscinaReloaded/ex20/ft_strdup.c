/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:07:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 13:10:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char			*dup;
	unsigned int	size;
	unsigned int	i;

	size = ft_strlen(src);
	dup = (char *)malloc(size + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
