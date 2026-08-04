/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:42:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/24 22:01:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

int	main(void)
{
	
	{
		char	*res;
		char	t[] ="HOla mundo!";

		res = ft_strdup(t);
		printf("ft_strdup: %p _%s_ res: %p _%s_\n", t, t, res, res);
		free (res);
		res = NULL;
		res = strdup(t);
		printf("strdup: %p _%s_ res: %p _%s_\n", t, t, res, res);
		free (res);
		res = NULL;
		printf("\n");

	}

	{
		char	*res;
		char	t[] ="";

		res = ft_strdup(t);
		printf("ft_strdup: %p _%s_ res: %p _%s_\n", t, t, res, res);
		free (res);
		res = NULL;
		res = strdup(t);
		printf("strdup: %p _%s_ res: %p _%s_\n", t, t, res, res);
		free (res);
		res = NULL;
		printf("\n");

	}

	return (0);
}