/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:08:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 14:11:04 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	hits;
	int	i;

	hits = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		if ((*f)(tab[i]) == 1)
			hits++;
		i++;
	}
	return (hits);
}
