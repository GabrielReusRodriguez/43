/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 20:52:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_H
# define EXPANSOR_H

# include "libft.h"
# include "tokenizer/token.h"
# include "env/environment.h"

//expansor/expansor.c
bool	expansor_expand(t_list **token_list, t_environment env);

//expansor/expansor_utils.c
void	expansor_find_var(const char *cmd, int *init, int *final, int len);

//expansor/expansor_cmd.c
bool	expansor_expand_string(const char *cmd, t_environment env, \
			char **new_cmd);

#endif