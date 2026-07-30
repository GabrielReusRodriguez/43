/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:40 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/02 17:24:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static	void	ft_format_init(t_format *format)
{
	format->b_dot = false;
	format->b_hash = false;
	format->b_minus = false;
	format->b_plus = false;
	format->b_space = false;
	format->b_zero = false;
	format->c_conv_type = ' ';
	format->len = 0;
	format->n_precision = FORMAT_PRECISION_INIT;
	format->n_width = FORMAT_WIDTH_INIT;
}

static bool	ft_format_is_suported_type(char c)
{
	return (ft_strchr(SUPORTED_TYPES, c) != NULL);
}

static void	ft_format_parse_flag(const char *str, size_t *j, t_format *format)
{
	if (ft_format_parse_prefix_flags(str, j, format))
		return ;
	ft_format_parse_padding_flags(str, j, format);
}

void	*ft_format_get(const char *str, t_format *format)
{
	size_t	j;

	j = 0;
	ft_format_init(format);
	while (str[j] != '\0' && !ft_format_is_suported_type(str[j]))
		ft_format_parse_flag(str, &j, format);
	format->len = j;
	if (ft_format_is_suported_type(str[j]))
		format->c_conv_type = str[j];
	else
		return (NULL);
	return (format);
}
