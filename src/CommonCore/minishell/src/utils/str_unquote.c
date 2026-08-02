/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_unquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:27:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/12/21 20:59:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "utils/string.h"

static void	free_components(char *hdr, char *body, char *tail)
{
	free(hdr);
	free(body);
	free(tail);
}
/*
static bool	join_compontents(const char *hdr, const char *body, \
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
*/
static bool	remove_quotes(const char *txt, int init, int final, char **unquoted)
{
	char	*header;
	char	*body;
	char	*tail;
	int		len;

	len = ft_strlen(txt);
	header = ft_substr(txt, 0, init);
	if (header == NULL)
		return(ft_err_errno(NULL), false);
	body = ft_substr(txt, init + 1, final - init - 1);
	if (body == NULL)
	{
		free(header);
		return(ft_err_errno(NULL), false);
	}
	tail = ft_substr(txt, final + 1, len - init);
	if (tail == NULL)
	{
		free(header);
		free(body);
		return(ft_err_errno(NULL), false);
	}
	if (!utils_str_join_compontents(header, body, tail, unquoted))
		return (free_components(header, body, tail), false);
	return(free_components(header, body, tail), true);
}    

static void	find_quote_end(const char *txt, char quote, int init, int *final)
{
	int i;

	*final = -1;
	i = init;
	while (txt[i] != '\0')
	{
		if (txt[i] == quote)
		{
			*final = i;
			return ;
		}
		if (txt[i] == '\\')
			i++;
		i++;
	}
}

bool	utils_string_unquote(const char *original, char **unquoted)
{
	int		i;
	int		final;
	bool	quote_found;
	
	i = 0;
	*unquoted = NULL;
	quote_found = false;
	while (original[i] != '\0')
	{
		if (original[i] == '\\')
		{
			i+=2;
			continue;
		}
		if (original[i] == '\"' || original[i] == '\'')
		{
			quote_found = true;
			find_quote_end(original, original[i], i + 1, &final);
			if (final == -1)
				break;
			if (!remove_quotes(original, i, final, unquoted))
			{
				if (*unquoted != NULL)
					free (*unquoted);
				return (false);
			}
			i = final;
			continue;
		}
		i++;
	}
	if (!quote_found)
	{
		*unquoted = ft_strdup(original);
		if (*unquoted == NULL)
			return (ft_err_errno(NULL), false);
	}
	return (true);
}