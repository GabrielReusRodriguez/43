/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:17 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/25 21:20:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#define FIRST_PRINTABLE_CHAR 32
#define LAST_PRINTABLE_CHAR 126

int	ft_str_is_printable(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (0);
	}
	string = str;
	while (*string != '\0')
	{
		if (!(*string >= FIRST_PRINTABLE_CHAR
				&& *string <= LAST_PRINTABLE_CHAR))
		{
			return (0);
		}
		string++;
	}
	return (1);
}
