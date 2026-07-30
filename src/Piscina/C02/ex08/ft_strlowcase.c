/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:26:13 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 21:26:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strlowcase(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (NULL);
	}
	string = str;
	while (*string != '\0')
	{
		if (*string >= 'A' && *string <= 'Z')
		{
			*string = *string + 32;
		}
		string++;
	}
	return (str);
}
