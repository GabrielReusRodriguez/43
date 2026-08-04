/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:36 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/21 12:06:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

#define SIZE 100

int main(void)
{
	char t1[] = "";
	char t2[] = "Hola mundo!";
	char t3[] = "Gab";
	char *res;
	char *res_cpy;

	res = (char *)malloc(SIZE);
	if (res == NULL)
	{
		printf("ERROR al reservar memoria");
		return (1);
	}
	res_cpy = (char *)malloc(SIZE);
	if (res_cpy == NULL)
	{
		printf("ERROR al reservar memoria");
		return (1);
	}
	bzero(res, SIZE);
	bzero(res_cpy, SIZE);
	res = ft_strcpy(res, t2);
	res_cpy = strcpy(res_cpy, t2);
	printf("ft_strcpy : \tsrc: _%s_ \tdest: _%s_\n", t2, res);
	printf("strcpy : \tsrc: _%s_ \tdest: _%s_\n", t2, res_cpy);
	
	bzero(res, SIZE);
	bzero(res_cpy, SIZE);
	res = ft_strcpy(res, t3);
	res_cpy = strcpy(res_cpy, t3);
	printf("ft_strcpy : \tsrc: _%s_ \tdest: _%s_\n", t3, res);
	printf("strcpy : \tsrc: _%s_ \tdest: _%s_\n", t3, res_cpy);

	bzero(res, SIZE);
	bzero(res_cpy, SIZE);
	res = ft_strcpy(res, t1);
	res_cpy = strcpy(res_cpy, t1);
	printf("ft_strcpy : \tsrc: _%s_ \tdest: _%s_\n", t1, res);
	printf("strcpy : \tsrc: _%s_ \tdest: _%s_\n", t1, res_cpy);

	free(res);
	free(res_cpy);

	return (0);
}
