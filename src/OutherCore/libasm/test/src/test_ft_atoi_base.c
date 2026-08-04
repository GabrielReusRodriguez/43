/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:57:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/27 21:58:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "libft.h"

int	main(void)
{
//int		ft_atoi_base(const char *str, int str_base)
	{
		char t[] = "0";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}
	{
		char t[] = "123";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}

	{
		char t[] = "00000";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}
	{
		char t[] = "-000";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}
	{
		char t[] = "-123";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}
	{
		char t[] = "   4560";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}
	{
		char t[] = "9";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,8));
		printf("\n");
	}
	{
		char t[] = "10";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,8));
		printf("\n");
	}
	{
		char t[] = "AB";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,16));
		printf("\n");
	}
	{
		char t[] = "1A0";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,16));
		printf("\n");
	}
	{
		char t[] = "-a10";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,16));
		printf("\n");
	}

	{
		char t[] = "Z";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,16));
		printf("\n");
	}
	{
		char t[] = "1T0";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,8));
		printf("\n");
	}
	{
		char t[] = "";
		printf("Valor test: _%s_ int %d\n",t, ft_atoi_base(t,10));
		printf("\n");
	}







	return (0);
}