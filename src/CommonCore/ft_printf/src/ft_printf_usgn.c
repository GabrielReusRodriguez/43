/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:22:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

static int	ft_format(t_format format, char **str)
{
	if (format.b_dot || format.b_minus)
		format.b_zero = false;
	if (ft_format_precision(format, str) < 0)
		return (-1);
	if (ft_format_width(format, str, 0) < 0)
		return (-1);
	return (0);
}

/*Sign flags + and space do not have sense with unsigned . 
	When we compile it gives you a "warning"*/
/* We add first precision and then we fill up to width.*/
int	ft_printf_usgn(int fd, va_list argp, t_format format)
{
	unsigned int	arg_value;
	char			*ch_number;
	int				num_bytes;

	arg_value = va_arg(argp, unsigned int);
	ch_number = ft_utoa(arg_value);
	if (ch_number == NULL)
		return (-1);
	if (ft_format(format, &ch_number) < 0)
		return (free (ch_number), -1);
	num_bytes = ft_iputstr_fd(ch_number, fd);
	free (ch_number);
	return (num_bytes);
}
