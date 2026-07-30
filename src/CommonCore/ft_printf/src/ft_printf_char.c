/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:24:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

//The 0 flags is not used with chars because it compiles with warning.

static	int	ft_format(t_format format, char **str)
{
	if (ft_format_width(format, str, 1) < 0)
		return (-1);
	if (ft_format_precision(format, str) < 0)
		return (-1);
	return (0);
}

/*Sign flags + and space do not have sense with char . 
	When we compile it gives you a "warning"*/
/* Zero flag  does not have sense in char*/
/*
	We generate the padding and we print char and padding 
	separated becasue ft_putstr prints string until \0
	and \0 could be an char passed by arg.
*/
int	ft_printf_char(int fd, va_list argp, t_format format)
{
	char	c;
	char	*str;
	int		num_bytes;

	format.b_zero = false;
	format.b_space = false;
	format.b_dot = false;
	c = va_arg(argp, int);
	str = ft_calloc(sizeof(char), 1);
	if (str == NULL)
		return (-1);
	if (ft_format(format, &str) < 0)
		return (free (str), -1);
	if (format.b_minus)
	{
		num_bytes = ft_iputchar_fd(c, fd);
		num_bytes += ft_iputstr_fd(str, fd);
	}
	else
	{
		num_bytes = ft_iputstr_fd(str, fd);
		num_bytes += ft_iputchar_fd(c, fd);
	}
	return (free (str), num_bytes);
}
