/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/02 17:24:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

bool	ft_format_parse_prefix_flags(const char *str, size_t *j, \
					t_format *format)
{
	if (str[*j] == '+' || str[*j] == '#')
	{
		if (str[*j] == '+')
			format->b_plus = true;
		if (str[*j] == '#')
			format->b_hash = true;
		*j = *j + 1;
		return (true);
	}
	return (false);
}
