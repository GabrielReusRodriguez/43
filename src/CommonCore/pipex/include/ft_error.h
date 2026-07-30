/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:19:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 18:25:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

void	ft_error_print_errno(const char *msg);
void	ft_error_print_errno_and_exit(const char *msg, int exit_status);
void	ft_error_print_str(const char *str);
void	ft_error_print_str_and_exit(const char *str, int exit_status);
void	ft_error_print_code(int code);

#endif