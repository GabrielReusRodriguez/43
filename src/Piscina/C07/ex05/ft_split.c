/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:02:57 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/14 15:17:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_check_separator(char character, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == character)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

static int	ft_count_tokens(char *str, char *charset)
{
	int	num_tokens;

	num_tokens = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		while (ft_check_separator(*str, charset) == 1 && *str != '\0')
			str++;
		if (*str != '\0')
			num_tokens++;
		while (ft_check_separator(*str, charset) == 0 && *str != '\0')
			str++;
		if (*str != '\0')
			str++;
	}
	num_tokens++;
	return (num_tokens);
}

static char	*ft_strncpy(char *src, int n)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(n);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	get_token(char **str, char *charset)
{
	int	size;

	size = 0;
	while (ft_check_separator(**str, charset) == 0 && **str != '\0')
	{
		size++;
		(*str)++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	int		num_tok;
	char	**tokens;
	char	*init_token;
	int		size_token;
	int		i;

	i = 0;
	num_tok = ft_count_tokens(str, charset);
	tokens = (char **)malloc(num_tok * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (*str != '\0')
	{
		while (ft_check_separator(*str, charset) == 1 && *str != '\0')
			str++;
		init_token = str;
		size_token = get_token(&str, charset);
		if (size_token > 0)
		{
			tokens[i] = ft_strncpy(init_token, size_token);
			i++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
