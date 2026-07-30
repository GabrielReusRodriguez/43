/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:29:06 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 14:24:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*ptr;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	ptr = (int *)malloc(size * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*ptr;
	int min;
	int max;

	min = -1,
	max = 5;
	ptr = ft_range(min,max);
	printf("\n");
	for(int i = 0; i < (max - min); i++)
	{
		printf("%d, ", ptr[i]);
	}
	printf("\n");

}
*/
