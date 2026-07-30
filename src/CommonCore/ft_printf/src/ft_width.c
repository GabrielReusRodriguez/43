/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:06:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:22:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"

/*
If we geet precision with numeric conversion, zero flag is ignored.
prefix_len: chars reserved for a prefix (+, -, space, 0x...) printed later.
*/
int	ft_format_width(t_format format, char **str, int prefix_len)
{
	int		len;

	if (format.n_width > 0)
	{
		len = ft_strlen(*str) + prefix_len;
		if ((int)format.n_width - len <= 0)
			return (0);
		if (ft_add_padding(format, str, format.n_width, len) < 0)
			return (-1);
	}
	return (0);
}
