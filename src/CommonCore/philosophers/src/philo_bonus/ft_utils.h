/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:18:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/15 00:00:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef unsigned char	t_bool;

# define TRUE 1
# define FALSE 0

int		ft_utils_atoi(const char *number);
int		ft_utils_ctoi(char number);
t_bool	ft_utils_isdigit(char character);
t_bool	ft_utils_contains_num(const char *str);
int		ft_utils_strlen(const char *str);
void	ft_utils_print(int fd, const char *str);
char	*ft_utils_strjoin(char *str1, char*str2);
char	*ft_utils_itoa(int n);

#endif