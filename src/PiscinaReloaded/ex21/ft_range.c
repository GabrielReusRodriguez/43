/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:21:00 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/04 13:30:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ptr;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	ptr = (int *)malloc(size * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	i = 0;
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
	int i;
	int min;
	int max;
	int *ptr;

	min = -5;
	max = 6;
	ptr = ft_range(min,max);
	i = 0;
	while(i < 11)
	{
		printf("%d ",ptr[i]);
		i++;
	}
		printf("\n");


	
}
*/
