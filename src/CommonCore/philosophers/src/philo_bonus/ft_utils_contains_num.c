/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_contains_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:06:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 18:35:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_utils.h"

t_bool	ft_utils_contains_num(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_utils_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
