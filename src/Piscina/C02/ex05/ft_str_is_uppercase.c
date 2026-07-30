/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:27 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/28 17:44:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_str_is_uppercase(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (0);
	}
	string = str;
	while (*string != '\0')
	{
		if (!(*string >= 'A' && *string <= 'Z'))
		{
			return (0);
		}
		string++;
	}
	return (1);
}
