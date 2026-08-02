/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:19:12 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 00:07:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	args_validate_uint(const char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (false);
		i++;
	}
	if (i > 0)
		return (true);
	else
		return (false);
}
