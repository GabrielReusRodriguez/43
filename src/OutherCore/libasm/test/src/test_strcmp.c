/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:06:53 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/21 12:24:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "libft.h"

int main(void)
{
	{
		char    t1[] ="";
		char    t2[] ="";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}
	
	{
		char    t1[] ="";
		char    t2[] ="Gabriel";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}

	{
		char    t1[] ="";
		char    t2[] ="Gabriel";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}

	{
		char    t1[] ="Gabrielin";
		char    t2[] ="Gabriel";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}

	{
		char    t1[] ="Gabriel";
		char    t2[] ="Gabrielin";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}

	{
		char    t1[] ="Gabriel";
		char    t2[] ="Gabriel";

		printf("ft test \ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,ft_strcmp(t1,t2));
		printf("test \t\ts1 _%s_ s2 _%s_ ret %d\n", t1,t2,strcmp(t1,t2));
		printf("\n");
	}

	return (0);
}