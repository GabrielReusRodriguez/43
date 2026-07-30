/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:54:52 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 22:18:18 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *nbr)
{
	int				number;
	int				sign;

	sign = 1;
	if (*nbr == '-')
	{
		sign = -1;
		nbr++;
	}
	number = 0;
	while (*nbr != '\0')
	{
		if (*nbr >= '0' && *nbr <= '9')
			number = number * 10 + (*nbr - '0');
		else
			return (sign * number);
		nbr++;
	}
	return (sign * number);
}
