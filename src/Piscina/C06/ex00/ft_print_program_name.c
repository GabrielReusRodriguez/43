/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:33:17 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/06 19:07:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstr(char *string)
{
	while (*string != '\0')
	{
		write(1, string, 1);
		string++;
	}
}

int	main(int argc, char **argv)
{
	int	x;

	x = argc;
	x++;
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}
