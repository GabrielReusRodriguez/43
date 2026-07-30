/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:22:13 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 21:25:03 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strupcase(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (NULL);
	}
	string = str;
	while (*string != '\0')
	{
		if (*string >= 'a' && *string <= 'z')
		{
			*string = *string - 32;
		}
		string++;
	}
	return (str);
}
