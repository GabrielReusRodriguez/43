/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:56:07 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 20:57:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_str_is_lowercase(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (0);
	}
	string = str;
	while (*string != '\0')
	{
		if (!(*string >= 'a' && *string <= 'z'))
		{
			return (0);
		}
		string++;
	}
	return (1);
}
