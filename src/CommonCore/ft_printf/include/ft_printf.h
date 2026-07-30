/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/01 23:44:59 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

# define DATA_TYPE_CHAR		'c'
# define DATA_TYPE_STR		's'
# define DATA_TYPE_PTR		'p'
# define DATA_TYPE_DEC		'd'
# define DATA_TYPE_INT		'i'
# define DATA_TYPE_USG		'u'
# define DATA_TYPE_HEX_LOW	'x'
# define DATA_TYPE_HEX_UP	'X'
# define DATA_TYPE_PERCENT	'%'

# define SUPORTED_TYPES "cspdiuxX%"
# define NUMERIC_CONVERSION "diuxX"

# define FORMAT_WIDTH_INIT 0
# define FORMAT_PRECISION_INIT -1

typedef struct s_format
{
	bool		b_minus;
	bool		b_zero;
	bool		b_dot;
	bool		b_hash;
	bool		b_space;
	bool		b_plus;
	int			n_precision;
	size_t		n_width;
	char		c_conv_type;
	size_t		len;
}	t_format;

int			ft_printf(char const *str, ...);
int			ft_printf_fd(int fd, char const *str, ...);
int			ft_printf_char(int fd, va_list argp, t_format format);
int			ft_printf_str(int fd, va_list argp, t_format format);
int			ft_printf_ptr(int fd, va_list argp, t_format format);
int			ft_printf_dec(int fd, va_list argp, t_format format);
int			ft_printf_int(int fd, va_list argp, t_format format);
int			ft_printf_usgn(int fd, va_list argp, t_format format);
int			ft_printf_hex(int fd, unsigned long number, bool up_case, \
				t_format format);
int			ft_printf_low_hex(int fd, va_list argp, t_format format);
int			ft_printf_up_hex(int fd, va_list argp, t_format format);
int			ft_printf_percent(int fd, t_format format);
void		*ft_format_get(char const *str, t_format *format);

int			ft_format_width(t_format format, char **str, int prefix_len);
int			ft_format_precision(t_format format, char **str);
int			ft_add_padding(t_format format, char **str, int padding_len, \
				int str_len);
bool		ft_format_parse_prefix_flags(const char *str, size_t *j, \
					t_format *format);
bool		ft_format_parse_padding_flags(const char *str, size_t *j, \
					t_format *format);

#endif