/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:27:26 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:28:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

int		ft_strlen(const char *arg);
void	ft_putstr(int fd, const char * str);
void	ft_putendl(int fd, const char * str);
size_t	ft_atou(const char *arg);
void	*ft_free(void *ptr);

#endif