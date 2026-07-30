/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:21:05 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/07 14:41:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (-1);
	}
	*range = (int *)malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < size)
	{
		range[0][i] = min + i;
		i++;
	}
	return (size);
}
/*

int main(void)
{
	int **range;
	int min;
	int max;
	int res;
	int **gab;

	range = (int **)malloc(sizeof(int *));
	min = -1;
	max=5;
	gab = NULL;
	printf("PRE res = %d pointer = %p \n",res, range);
	res = ft_ultimate_range(range,0,0);
	printf("POST res = %d pointer = %p \n",res, range);
	printf("Puntero a NULL %p\n",gab);
}
*/
