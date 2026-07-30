/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:48:47 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 20:51:56 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_str_is_numeric(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (0);
	}
	string = str;
	while (*string != '\0')
	{
		if (!(*string >= '0' && *string <= '9'))
		{
			return (0);
		}
		string++;
	}
	return (1);
}
