/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:52:05 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/28 23:37:39 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

static int	ft_strcmp_wrap(char *a, char *b)
{
	return (strcmp(a, b));
}

void	print_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("\t_%s_\n", tab[i]);
		i++;
	}
}

char	**ptr_dup(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **)malloc((argc + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (i < argc)
	{
		tab[i] = argv[i];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(int argc, char **argv)
{
	char	**tab;

	tab = ptr_dup(argc, argv + 1);
	if (tab == NULL)
		return (1);
	printf("PRE-sorted\n");
	print_tab(tab);
	tab = argv + 1;
	ft_advanced_sort_string_tab(tab, ft_strcmp_wrap);
	printf("POST-sorted\n");
	print_tab(tab);
	return (0);
}
