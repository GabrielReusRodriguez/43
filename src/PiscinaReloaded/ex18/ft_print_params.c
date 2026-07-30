/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:36:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 18:24:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	ft_printstr(char *s)
{
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_printstr(argv[i]);
		i++;
	}
	return (0);
}
