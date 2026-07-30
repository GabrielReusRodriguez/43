/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_bool.h"

unsigned int    ft_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size && *src != '\0' )
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i++;
	while ( i < size)
	{
		dest[i] = '\0';
		i++;
	}
	
}

char	*ft_strncat(char *dest, char *src, int size)
{
	int		i;
	char 	*destiny;

	destiny = dest;
	if (size == 0)
		return (destiny);
	while(*dest != '\0')
	{
		dest++;
	}
	i = 0;
	while(*src != '\0' && i < size)
	{
		*dest = *src;
		i++;
	}
	while(i < size)
	{
		*dest  = '\0';
		dest++;
	}
	return (destiny);
}
