/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:23:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

/*Sign flags + and space do not have sense with strings . 
		When we compile it gives you a "warning"*/
/*The 0 flag does not apply to strings.*/
/* First we applu precision ( cut until n chars) and 
		then apply width fill up to width.*/
static	int	ft_format(t_format format, char **str)
{
	format.b_zero = false;
	format.b_space = false;
	format.b_plus = false;
	format.b_hash = false;
	if (ft_format_precision(format, str) < 0)
		return (-1);
	if (ft_format_width(format, str, 0) < 0)
		return (-1);
	return (0);
}

int	ft_printf_str(int fd, va_list argp, t_format format)
{
	char	*str;
	char	*arg;
	int		num_bytes;

	arg = va_arg(argp, char *);
	if (arg != NULL)
		str = ft_strdup(arg);
	else
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if (ft_format(format, &str) < 0)
		return (free (str), -1);
	num_bytes = ft_iputstr_fd(str, fd);
	free (str);
	return (num_bytes);
}
