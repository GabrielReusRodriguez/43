/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:42:32 by greus-ro          #+#    #+#             */
/*   Updated: 2023/11/30 15:42:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*string;

	if (str == NULL)
	{
		return ;
	}
	string = str;
	while (*string != '\0')
	{
		write(1, string, 1);
		string++;
	}
}

/*
int main(void)
{
	ft_putstr("Hola mundo!");
}
*/
