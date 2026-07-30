/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:41:48 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/30 15:41:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int		size;

	if (str == NULL)
	{
		return (0);
	}
	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}
