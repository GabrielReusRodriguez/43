/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:24 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 21:27:21 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	total;
	int	i;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	total = 1;
	i = 0;
	while (i < power)
	{
		total = total * nb;
		i++;
	}
	return (total);
}
