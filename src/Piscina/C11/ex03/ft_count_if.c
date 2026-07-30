/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:29:02 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 12:58:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	values_ok;

	i = 0;
	values_ok = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			values_ok++;
		i++;
	}
	return (values_ok);
}
