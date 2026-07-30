/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:48:38 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/06 19:09:22 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_compare_char(char c1, char c2)
{
	if (c1 > c2)
		return (1);
	if (c1 < c2)
		return (-1);
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	cmp;

	cmp = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		cmp = ft_compare_char(*s1,*s2);
		if (cmp != 0)
			return (cmp);
		s1++;
		s2++;
	}
	return (ft_compare_char(*s1,*s2));
}

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

static void	ft_print_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}

int	main(int argc2, char **argv2)
{
	int		i;
	int		j;
	char	*param;
	char	**argv;
	int		argc;

	argv = argv2 + 1;
	argc = argc2 - 1;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) == 1)
			{
				param = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = param;
			}
			j++;
		}
		i++;
	}
	ft_print_args(argc, argv);
}
