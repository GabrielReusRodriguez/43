/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:35:41 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/10 23:18:04 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	s = (char *)malloc(sizeof(strs));
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size -1)
		{
			s[c++] = sep[j++];
		}
		i++;
	}
	s[c] = '\0';
	return (s);
}
/* 
#include <stdio.h>
int check(char *msg)
{
	while(*msg != '\0')
	{
		msg++;
	}
	printf("FINITO\n");
	return (0);
}

int	main(int argc, char **argv)
{
   char	separators[]="_";
   char *msg = NULL;
   msg = ft_strjoin(argc - 1, argv + 1, separators);
	printf("Valor es: @%s@\n",msg);
	check(msg);
	return (0);
}
*/
