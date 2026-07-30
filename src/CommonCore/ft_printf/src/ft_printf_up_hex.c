/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_up_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:46 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:23:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*Sign flags + and space do not have sense with low hex . 
	When we compile it gives you a "warning"*/
/*Hashtag flag is treated at ft_print_hex*/
int	ft_printf_up_hex(int fd, va_list argp, t_format format)
{
	int				num_bytes;
	unsigned int	arg;

	arg = va_arg(argp, unsigned int);
	num_bytes = ft_printf_hex(fd, arg, true, format);
	return (num_bytes);
}
