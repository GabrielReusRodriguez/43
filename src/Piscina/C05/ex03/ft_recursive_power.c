/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:11:48 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 21:29:22 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	total;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	total = nb * ft_recursive_power(nb, power -1);
	return (total);
}
