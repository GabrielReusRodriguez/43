/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:44:21 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/05 18:25:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		cmp = s1[i] - s2[i];
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	ft_print_args(int argc, char **args)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		ft_printstr(args[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**sorted;
	char	*ptr;

	sorted = argv + 1;
	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1 - i)
		{
			if (ft_strcmp(sorted[j], sorted[j + 1]) > 0)
			{
				ptr = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = ptr;
			}
			j++;
		}
		i++;
	}
	ft_print_args(argc - 1, sorted);
	return (0);
}
