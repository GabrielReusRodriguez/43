/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:16:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 13:43:46 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libgen.h>
#include "ft_boolean.h"
#include <stdio.h>

/*
t_bool	ft_is_file(char *path)
{
	char	*file;
	
	printf("Entrando...\n");
	file = basename(path);
	printf("PRE _%s_ _%s_\n",path,file);
	if (file == NULL)
	{
		printf("NULL\n");
		return (FALSE);
	}
	if (*file == '/'  || *file == '.')
	{
		printf("Slash\n");
		return (FALSE);
	}
	printf("OK\n");
	return (TRUE);
}
*/
