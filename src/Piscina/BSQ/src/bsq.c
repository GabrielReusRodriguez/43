/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:27:21 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:42 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../headers/ft_map.h"
#include "../headers/ft_put.h"

int main(int argc, char **argv)
{
	t_map   *map;
	int		i;
	
	if(argc == 1)
	{
		ft_putline("Por consola");
		return (1); 
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr("Loading ");
		ft_putstr(argv[i]);
		ft_putline("...");
		map = ft_load_map(argv[i]);
		if(map == NULL)
		{
			ft_putline("Error al cargar el mapa");
			return (1);
		}
		ft_print_map(map);
		ft_free_map(map);
		ft_putchar('\n');
		i++;
	}
	return (0);
}