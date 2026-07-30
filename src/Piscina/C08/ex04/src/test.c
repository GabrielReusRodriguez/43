/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:18:13 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 17:15:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int main(int argc, char **argv)
{
	struct s_stock_str * ptr;
	int	i;

	ptr = ft_strs_to_tab(argc - 1 ,argv + 1);
	//ptr = ft_strs_to_tab(0,argv);
	if (ptr == NULL)
	{
		printf("ERROR\n");
		return (1);
	}
	i = 0;
	printf("PRE - entra %c \n",*(ptr->str));
	while (ptr->str != NULL)
	{
		printf("Estructura %d :\n",i);
		printf("\t size:  %d \n",ptr->size);
		printf("\t str : _%s_ \n",ptr->str);
		printf("\t copy: _%s_ \n",ptr->copy);
		printf("\n");
		i++;
		ptr++;
	}
	printf("Estructura final :\n");
	printf("\t size:  %d \n",ptr->size);
	printf("\t str : _%s_ \n",ptr->str);
	printf("\t copy: _%s_ \n",ptr->copy);
	if(ptr->str== NULL )
	{
		printf("Caracter final encontrado en %p\n", ptr->str);
	}
	if(ptr->copy == NULL )
	{
		printf("Caracter final encontrado en %p\n", ptr->copy);
	}
	printf("\n");
	printf("\n");

	return (0);
}
