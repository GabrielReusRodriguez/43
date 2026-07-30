/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:29:02 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 12:58:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_sign(char **nbr)
{
	int	sign;

	sign = 0;
	while (**nbr != '\0' && (**nbr == '-' || **nbr == '+'))
	{
		if (**nbr == '-')
			sign++;
		(*nbr)++;
	}
	if (sign % 2 == 1)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *nbr)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = ft_check_sign(&nbr);
	while (*nbr != '\0')
	{
		if (!(*nbr <= '9' && *nbr >= '0' ))
			return (result * sign);
		result = result * 10 + (*nbr - '0');
		nbr++;
	}
	return (result * sign);
}
