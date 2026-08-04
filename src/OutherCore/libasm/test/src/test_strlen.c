/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:45:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/20 18:53:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

int	main(void)
{
	char *t1 = "";
	char *t2 = "Hola mundo\n";

	printf("Test de _%s_ len: %ld \n", t1, ft_strlen(t1));
	printf("Test de _%s_ len: %ld \n", t2, ft_strlen(t2));
	return (0);
}