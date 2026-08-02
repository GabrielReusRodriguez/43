/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:47:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 20:52:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "tokenizer/token.h"


static void	expansor_find_end_var(const char *text, int init, int *final)
{
	int	i;

	i = init;
	while (text[i] != '\0' && text[i] != ' ' && text[i] != '$' && \
				text[i] != '\'' && text[i] != '\"')
		i++;
	*final = i;
}

void		expansor_find_var(const char *cmd, int *init, int *final, int len)
{
	int		i;

	i = *init;
	*init  = len + 1;
	*final	= len + 1;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '\\')
		{
			i+=2;
			continue;
		}
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] != '\'' && cmd[i] != '\0')
				i++;
			continue;
		}
		if (cmd[i] == '$')
		{
			*init = i;
			expansor_find_end_var(cmd, i + 1, final);
			return ;
		}
		i++;
	}
}
