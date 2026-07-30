/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:13:27 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 17:23:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf_dec(int fd, va_list argp, t_format format)
{
	return (ft_printf_int(fd, argp, format));
}
