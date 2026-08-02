/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:25:47 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/14 23:57:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"

char	*ft_utils_strjoin(char *str1, char *str2)
{
	char	*joined;
	int		i;
	int		size_str1;
	int		size_str2;

	size_str1 = ft_utils_strlen(str1);
	size_str2 = ft_utils_strlen(str2);
	joined = malloc(size_str1 + size_str2 + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < size_str1)
	{
		joined[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < size_str2)
	{
		joined[i + size_str1] = str2[i];
		i++;
	}
	joined[size_str1 + size_str2] = '\0';
	return (joined);
}
