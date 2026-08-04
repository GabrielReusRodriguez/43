/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:11:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/22 22:32:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libft.h"

int main(void)
{
	{
		char	t[] = "Hola mundo!";
		int		len;
		int		ret;

		len = strlen(t);
		
		{
			ret = write(STDOUT_FILENO, t, len);
			printf("write res: %d\n", ret);
			ret = ft_write(STDOUT_FILENO,t, len);
			printf("ft_write res: %d\n", ret);
			printf("\n");
		}
		{
			errno = 0;
			ret = write(-1, t, len);
			printf("write res: %d errno %d \n", ret, errno);
			errno = 0;
			ret = ft_write(-1,t, len);
			printf("ft_write res: %d errno %d \n", ret, errno);
			printf("\n");
		}
		{
			errno = 0;
			ret = write(400, t, len);
			printf("write res: %d errno %d \n", ret, errno);
			errno = 0;
			ret = ft_write(400,t, len);
			printf("ft_write res: %d errno %d \n", ret, errno);
			printf("\n");
		}
		{
			errno = 0;
			char t2[] = "";
			ret = write(STDOUT_FILENO, t2, 0);
			printf("write res: %d errno %d \n", ret, errno);
			errno = 0;
			ret = ft_write(STDOUT_FILENO,t2, 0);
			printf("ft_write res: %d errno %d \n", ret, errno);
			printf("\n");
		}


	}
	return (0);
}