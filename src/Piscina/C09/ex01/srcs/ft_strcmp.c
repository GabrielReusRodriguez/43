/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:41:25 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/14 18:49:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(char *s1, char *s2)
{
	char	*string1;
	char	*string2;
	int		cmp;

	cmp = 0;
	string1 = s1;
	string2 = s2;
	while (*string1 != '\0' && *string2 != '\0')
	{
		cmp = *string1 - *string2;
		if (cmp != 0)
		{
			return (cmp);
		}
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
