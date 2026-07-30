/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:35:56 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/29 18:02:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_str_is_alpha(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return (1);
	}
	string = str;
	while (*string != '\0')
	{
		if (!(
				(*string >= 'A' && *string <= 'Z')
				|| (*string >= 'a' && *string <= 'z')
			)
		)
		{
			return (0);
		}
		string++;
	}
	return (1);
}
