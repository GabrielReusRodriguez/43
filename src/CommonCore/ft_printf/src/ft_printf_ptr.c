/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:23:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"
#include "ft_printf.h"

static int	ft_format(t_format format, char **ptr)
{
	if (ft_format_precision(format, ptr) < 0)
		return (-1);
	if (ft_format_width(format, ptr, 0) < 0)
		return (-1);
	return (0);
}

static char	*ft_get_formated_hex(void *ptr)
{
	char	*formated_hex;
	char	*hex_str;

	if (ptr == NULL)
	{
		formated_hex = ft_strdup("(nil)");
		if (formated_hex == NULL)
			return (NULL);
	}
	else
	{
		hex_str = ft_htoa((unsigned long long)ptr, false);
		if (hex_str == NULL)
			return (NULL);
		formated_hex = ft_strjoin("0x", hex_str);
		free (hex_str);
		if (formated_hex == NULL)
			return (NULL);
	}
	return (formated_hex);
}

/*Sign flags + and space do not have sense with PTR . 
	When we compile it gives you a "warning"*/
int	ft_printf_ptr(int fd, va_list argp, t_format format)
{
	int		num_bytes;
	void	*ptr;
	char	*formated_hex;

	ptr = va_arg(argp, void *);
	format.b_plus = false;
	format.b_space = false;
	formated_hex = ft_get_formated_hex(ptr);
	if (formated_hex == NULL)
		return (-1);
	if (ft_format(format, &formated_hex) < 0)
		return (free (formated_hex), -1);
	num_bytes = ft_iputstr_fd(formated_hex, fd);
	return (free(formated_hex), num_bytes);
}
