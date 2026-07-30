/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:01:59 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:04:05 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
