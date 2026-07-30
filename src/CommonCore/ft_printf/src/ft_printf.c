/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:22:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf.h"

//static int	ft_print_special_char(int fd, char c, va_list argp)
static int	ft_print_special_char(int fd, char const *str, size_t *i, \
				va_list argp)
{
	t_format	format;

	if (ft_format_get(str + *i, &format) == NULL)
		return (-1);
	*i += format.len;
	if (format.c_conv_type == DATA_TYPE_CHAR)
		return (ft_printf_char(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_STR)
		return (ft_printf_str(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_PTR)
		return (ft_printf_ptr(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_DEC)
		return (ft_printf_dec(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_INT)
		return (ft_printf_int(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_USG)
		return (ft_printf_usgn(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_HEX_LOW)
		return (ft_printf_low_hex(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_HEX_UP)
		return (ft_printf_up_hex(fd, argp, format));
	if (format.c_conv_type == DATA_TYPE_PERCENT)
		return (ft_printf_percent(fd, format));
	return (0);
}

int	ft_printf_fd(int fd, char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	size_t	i;

	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], fd);
			num_bytes++;
		}
		else
		{
			i++;
			num_bytes = num_bytes + ft_print_special_char(fd, str, &i, argp);
		}
		i++;
	}
	va_end(argp);
	return (num_bytes);
}

int	ft_printf(char const *str, ...)
{
	va_list	argp;
	int		num_bytes;
	size_t	i;

	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			num_bytes++;
		}
		else
		{
			i++;
			num_bytes += ft_print_special_char(STDOUT_FILENO, str, &i, argp);
		}
		i++;
	}
	va_end(argp);
	return (num_bytes);
}
