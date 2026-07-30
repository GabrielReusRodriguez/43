/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:22:51 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 14:18:37 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_ptr_size(char *str)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*new_string;

	i = 0;
	size = ft_get_ptr_size(src);
	new_string = (char *)malloc(size + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < size)
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
