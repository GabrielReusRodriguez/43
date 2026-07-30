/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:46:56 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/29 21:44:21 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	ft_compare_strings(const char *string, const char *find)
{
	char	*str;
	char	*str_find;

	str = (char *)string;
	str_find = (char *)find;
	while (*str == *str_find && *str_find != '\0')
	{
		str++;
		str_find++;
	}
	if (*str_find == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strstr(char *str, char *find)
{
	char				*string;

	string = str;
	if (*find == '\0')
		return (str);
	while (*string != '\0')
	{
		if (*string == *find)
		{
			if (ft_compare_strings(string, find) == 1)
			{
				return (string);
			}
		}
		string++;
	}
	return (NULL);
}
