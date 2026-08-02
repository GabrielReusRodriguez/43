/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:33:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 19:47:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer/token.h"
#include "expansor.h"
#include "env/environment.h"
#include "utils/string.h"

#include <stdio.h>
#include <stdlib.h>

static	bool expansor_init(t_str_fragment *str_treated, t_str_fragment *hit, \
				char **new_txt)
{

	*str_treated = utils_new_str_fragment();
	*hit = utils_new_str_fragment();
	*new_txt = ft_strdup("");
	if (*new_txt == NULL)
		return(ft_err_errno(NULL), false);
	return (true);	
}

static bool	expansor_add_hdr(const char *original,t_str_fragment str_treated, \
				int len, char **new_txt)
{
	char	*hdr;
	char	*tmp;

	if (len > 0)
	{
		hdr = ft_substr(original, str_treated.end, len);
		if (hdr == NULL)
			return (ft_err_errno(NULL),false);
		tmp = *new_txt;
		*new_txt = ft_strjoin(tmp, hdr);
		free (tmp);
		free (hdr);
		if (*new_txt == NULL)
			return (ft_err_errno(NULL), false);
	}
	return (true);
}

static bool expansor_add_var(const char *original, t_str_fragment var_hit, \
				t_environment env, char **new_txt)
{
	char	*key;
	char	*value;
	char	*tmp;

	key = ft_substr(original, var_hit.begin, var_hit.end - var_hit.begin);
	if (key == NULL)
		return (false);
	if(!env_get_var(env, key, &value))
		return (free(key), false);
	free (key);
	tmp = *new_txt;
	*new_txt = ft_strjoin(tmp, value);
	free (value);
	free (tmp);
	if (*new_txt == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}

bool	expansor_expand_string(const char *cmd, t_environment env, char **new_cmd)
{
	t_str_fragment	str_treated;
	t_str_fragment	var_hit;
	int		len;

	if (!expansor_init(&str_treated, &var_hit, new_cmd))
		return (false);
	len = ft_strlen(cmd);
	while (str_treated.end < len)
	{
//		if (cmd[var_hit.begin] == '\'')
//		{
//			printf("Comillas\n");
//			var_hit.begin++;
//			while(cmd[var_hit.begin] != '\0' && cmd[var_hit.begin] != '\'')
//				var_hit.begin++;
//		}		
		expansor_find_var((char *)cmd, &var_hit.begin, &var_hit.end, len);
		if (var_hit.end <= len)
		{
			if (!expansor_add_hdr(cmd, str_treated, var_hit.begin - str_treated.end, new_cmd))
				return (free(*new_cmd), false);
			if  (!expansor_add_var(cmd, var_hit, env, new_cmd))
				return (free (*new_cmd), false);
			str_treated.end = var_hit.end;
			var_hit.begin = var_hit.end;
		}
		else
			break;
	}
	if (!expansor_add_hdr(cmd, str_treated, len - str_treated.end, new_cmd))
		return (false);
	return (true);
}
