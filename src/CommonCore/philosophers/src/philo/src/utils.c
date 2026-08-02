/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:27 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/23 00:28:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(const char *arg)
{
	int	size;

	size = 0;
	while (arg[size] != '\0')
		size++;
	return (size);
}

void	ft_putstr(int fd, const char * str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putendl(int fd, const char * str)
{
	ft_putstr(fd, str);
	ft_putstr(fd, "\n");
}

size_t	ft_atou(const char *arg)
{
	size_t	value;
	size_t	i;

	i = 0;
	value = 0;
	while(arg[i] != '\0')
	{
		value = value * 10 + arg[i] -'0';
		i++;
	}
	return (value);
}

void	*ft_free(void *ptr)
{
	if (ptr != NULL)
	{
		free (ptr);
	}
	return (NULL);
}
