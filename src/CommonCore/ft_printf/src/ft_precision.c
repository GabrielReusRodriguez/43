/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:34:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/02 17:24:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"

/*With strings , precision printfs n firsts chars*/
static int	ft_format_string_precision(t_format format, char **str)
{
	char	*formated_str;

	if (format.n_precision >= 0)
	{
		formated_str = ft_substr(*str, 0, format.n_precision);
		if (formated_str == NULL)
			return (-1);
		free (*str);
		*str = formated_str;
	}
	return (0);
}

static int	ft_create_empty_str(char **str)
{
	char	*formated_str;

	formated_str = ft_strdup("");
	if (formated_str == NULL)
		return (-1);
	free (*str);
	*str = formated_str;
	return (0);
}

/* with numeric format and precision is informed, 0 flag is ignored*/
/* If it is numeric, we force the b_minus false and b_zero true flags 
because we have to add zeros to the left (less significant numbers)*/
/*Special case %.d with value 0 is an empty string*/
static int	ft_format_numeric_precision(t_format format, char **str)
{
	int		len;

	if (format.n_precision >= 0)
	{
		if (ft_strcmp(*str, "0") == 0 && format.n_precision == 0)
			return (ft_create_empty_str(str));
		len = ft_strlen(*str);
		if ((int)format.n_precision - len <= 0)
			return (0);
		if (ft_add_padding(format, str, format.n_precision, len) < 0)
			return (-1);
	}
	return (0);
}

int	ft_format_precision(t_format format, char **str)
{
	if (ft_strchr(NUMERIC_CONVERSION, format.c_conv_type) != NULL)
	{
		format.b_zero = true;
		format.b_minus = false;
		return (ft_format_numeric_precision(format, str));
	}
	if (ft_strchr("s", format.c_conv_type) != NULL)
		return (ft_format_string_precision(format, str));
	return (0);
}
