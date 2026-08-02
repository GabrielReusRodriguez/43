/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:30:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:21:15 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

#include "env/environment.h"

static bool env_new_empty_var(t_pair **pair, const char *line)
{
	*pair = (t_pair *)malloc(sizeof(t_pair));
	if (*pair == NULL)
		return (ft_err_errno(NULL), false);
	if (!pair_init(*pair, line, ""))
	{
		free (*pair);
		return (false);
	}
	return (true);
}

static bool env_extract_pair(const char *line, int pos_separator, char **key, \
				char **value)
{
	int		len;

	len = ft_strlen(line);
	*key = ft_substr(line, 0, pos_separator);
	if (*key == NULL)
		return (ft_err_errno(NULL), false);
	*value = ft_substr(line, pos_separator + 1, len - pos_separator);
	if (*value == NULL)
	{
		*value = ft_strdup("");
		if (*value == NULL)
		{
			free (*key);
			return (ft_err_errno(NULL), false);
		}
	}
	return (true);
}

static bool env_new_var(t_pair **pair, const char *line)
{
	char	*_value;
	char	*_key;
	int		pos_equal;
	bool	result;
	
	pos_equal = ft_istrchr((char *)line,  "=");
	if (pos_equal < 0)
		return (env_new_empty_var(pair, line));
	else
		if (!env_extract_pair(line, pos_equal, &_key, &_value))
			return (false);
	*pair = (t_pair *)malloc(sizeof(t_pair));
	if (*pair == NULL)
	{
		free (_key);
		free (_value);
		return (ft_err_errno(NULL), false);
	}
	result = pair_init(*pair, _key, _value);
	free (_key);
	free (_value);
	return (result);
}

/*With strchr , we get a pointer pointing the first occurrence of char
	or NULL if it is not present.
	So, we must NOT  free the memory of this pointer.
*/
static bool	env_parse_line(t_environment *env, const char *line)
{
	char	*line_value;
	t_pair	*pair;
	t_list	*node;

	pair = NULL;
	line_value = ft_strchr(line, '=');
	if (line_value == NULL)
	{
		if (!env_new_empty_var(&pair, line))
			return (false);
	}
	else
	{
		if (!env_new_var(&pair, line))
			return (false);
	}
	node = ft_lstnew(pair);
	if (node == NULL)
	{
		pair_destroy(pair);
		free (pair);
		return (ft_err_errno(NULL), false);
	}
	ft_lstadd_back(&env->vars, node);
	return (true);
}

#include <stdio.h>

bool	env_load(t_environment *env, const char **main_env)
{
	char	**env_line;

	if (main_env == NULL)
	{
		env->vars = NULL;
		return (false);
	}
	env_line = (char **)main_env;
	while (*env_line != NULL)
	{
		if (!env_parse_line(env, *env_line))
		{
			env_destroy(env);
			return (false);
		}
		env_line++;
	}
	return (true);
}

# include <stdio.h>
void	env_debug(t_environment env)
{

	t_list *node;
	t_pair *pair;

	printf("ENV DEBUG ************************\n");	
	node = env.vars;
	while (node != NULL)
	{
		pair = (t_pair*)node->content;
		printf("\tKey: _%s_ Value:  _%s_\n", pair->key, pair->value);
		node = node->next;
	}
	printf("FIN ENV DEBUG ********************\n");	

}
