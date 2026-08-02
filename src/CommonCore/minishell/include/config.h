/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:10:58 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 12:45:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "colours.h"

//# define  SHELL_DEFAULT_PROMPT "minishell> " 

# define  SHELL_DEFAULT_PROMPT COLOUR_BLUE "minishell> " COLOUR_RST 

typedef struct s_shell_config
{
	int fd_copy_stdin;
	int fd_copy_stdout;
	
} t_shell_config;

#endif