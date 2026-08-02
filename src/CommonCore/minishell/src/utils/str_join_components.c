/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:22:27 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 19:03:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

bool	utils_str_join_compontents(const char *hdr, const char *body, \
				const char *tail, char **final)
{
	char	*tmp;

	tmp = ft_strjoin(hdr, body);
	if (tmp == NULL)
		return (ft_err_errno(NULL), false);
	*final = ft_strjoin(tmp, tail);
	free (tmp);
	if (*final == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}
