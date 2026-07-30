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
	char	*string;
	int		size;

	if (str == NULL)
	{
		return (0);
	}
	size = 0;
	string = str;
	while (*string != '\0')
	{
		string++;
		size++;
	}
	return (size);
}

/*
int main(void)
{
	//char msg[]="Hola";
	printf(" ft_strlen: %d\n",ft_strlen(NULL));

}
*/
