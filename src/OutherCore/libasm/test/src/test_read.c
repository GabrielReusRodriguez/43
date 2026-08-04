/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:11:37 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/22 22:33:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <errno.h>

#include "libft.h"

#define SIZE 1000

int main(void)
{

	{
		char	buffer[SIZE];
		int		ret;
		int		fd;
		const char	*path = "src/test_read.c";
		
		bzero(buffer, SIZE);
		fd = open(path, O_RDONLY);
		ret = read(fd, buffer, SIZE);
		close (fd);
		printf(" read buffer _%.*s_ ret %d\n", ret > 80 ? 80 : ret, buffer, ret);
		printf("\n\n\n************************\n\n\n");
		bzero(buffer, SIZE);
		fd = open(path, O_RDONLY);
		ret = ft_read(fd, buffer, SIZE);
		close (fd);
		printf("ft_read buffer _%.*s_ ret %d\n", ret > 80 ? 80 : ret, buffer, ret);

		printf("\n\n\n");
	}
	{
		char	buffer[SIZE];
		int		ret;
		
		errno = 0;
		bzero(buffer, SIZE);
		ret = read(-1, buffer, SIZE);
		printf(" read buffer _%s_ ret %d errno %d\n",buffer, ret, errno);
		errno = 0;
		printf("\n\n\n************************\n\n\n");
		bzero(buffer, SIZE);
		ret = ft_read(-1, buffer, SIZE);
		printf(" ft_read buffer _%s_ ret %d, errno %d\n",buffer, ret, errno);

		printf("\n");
	}



	return (0);
}