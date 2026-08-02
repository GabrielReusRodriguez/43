/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/21 20:32:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cmd.h"
#include "libft.h"

static int	count_params(t_cmd *cmd)
{
	t_list *node;
	int		num;

	num = 0;
	node = cmd->args;
	while (node != NULL)
	{
		num++;
		node = node->next;
	}
	return (num);
}

static bool	get_memory(int num, char ***str_params)
{
	*str_params = (char **)malloc((num + 1) * sizeof(char *));
	if (*str_params == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}

static	void	free_memory(int num, char **str_params)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free (str_params[i]);
		i++;
	}
	free (str_params);
}

bool	cmd_export_params(t_cmd *cmd, char ***str_params)
{
	t_list	*node;
	int		num;
	int		i;
	char	**tmp_params;

	tmp_params = NULL;
	num = count_params(cmd);
	if (!get_memory(num, &tmp_params))
		return (false);
	i = 0;
	node = cmd->args;
	while (node != NULL)
	{
		tmp_params[i] = ft_strdup((char *)node->content);
		if (tmp_params[i] == NULL)
		{
			free_memory(i, tmp_params);
			return (ft_err_errno(NULL), false);
		}
		i++;
		node = node->next;
	}
	tmp_params[num] = NULL;
	*str_params = tmp_params;
	return (true);
}
