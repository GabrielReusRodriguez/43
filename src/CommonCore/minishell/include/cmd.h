/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:34:51 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 23:45:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <sys/types.h> 

# include "minishell.h"
# include "libft.h"
# include "tokenizer/token.h"
# include "pipe.h"

# define CMD_NO_PID -1
typedef enum e_cmd_type
{
	CMD_TYPE_NONE,
	CMD_TYPE_PIPE,
	CMD_TYPE_SINGLE

}	t_cmd_type;

typedef struct s_cmd
{
	t_list			*input_redirections;
	char			*executable;
	t_list			*args;
	t_list			*output_redirections;
	t_cmd_type		type;
	pid_t			pid;
	int				fd_out;
	int				fd_in;
	int				return_value;
}	t_cmd;

void	cmd_init(t_cmd *cmd);
t_cmd	cmd_new(void);
void	cmd_destroy(t_cmd *cmd);
void	cmd_debug(t_cmd *cmd);
void	cmd_clear_list_node(void *);


//bool	cmd_create_from_tokens(const t_list *tokens, t_cmd **cmd);
bool	cmd_parse_tokens(t_list *init, t_list *final, t_cmd **cmd);

bool	cmd_export_params(t_cmd *cmd, char ***str_params);

//cmd/cmd_fds.c
bool	cmd_open_redir_outputs(t_cmd *cmd);
bool	cmd_open_redir_inputs(t_cmd *cmd);

//cmd/cmd_redirections.c
bool	cmd_prepare_redirs(t_cmd *cmd);

#endif