/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:05:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 19:46:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_environment.h"
#include "ft_error.h"
#include "ft_exec.h"
#include "ft_fd.h"
#include "ft_files.h"
//#include "ft_ptr.h"
#include "ft_path.h"
#include "ft_parent.h"
#include "libft.h"

static void	ft_main_free_resources(int fdin, int fdout, t_env env, \
				const char *file_output)
{
	ft_file_close(fdin, fdout);
	ft_ptr_free_dchar_ptr(env.path);
	if (file_output != NULL)
		unlink(file_output);
}

static int	ft_main_execute_pipe(char **argv, t_env env, \
				int initial_cmd, int final_cmd)
{
	int	status;
	int	i;

	status = -1;
	i = initial_cmd;
	while (i < final_cmd)
	{
		status = ft_exec_redir_and_cmd(argv[i], env, NO_FD);
		if (status != 0)
			return (status);
		i++;
	}
	return (status);
}

static int	ft_main_get_first_cmd_pos(char **argv)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
		return (3);
	else
		return (2);
}

static int	ft_main_exec_cmds(char **argv, int argc, t_fds fds, t_env env)
{
	int		status;

	status = ft_main_execute_pipe(argv, env, \
				ft_main_get_first_cmd_pos(argv), argc - 2);
	if (status != 0)
	{
		ft_main_free_resources(fds.in, fds.out, env, argv[argc - 1]);
		exit(status);
	}
	status = ft_exec_redir_and_cmd(argv[argc - 2], env, fds.out);
	if (status != 0)
	{
		ft_main_free_resources(fds.in, fds.out, env, argv[argc - 1]);
		exit(status);
	}
	status = ft_parent_get_last_child_status(argc - \
				ft_main_get_first_cmd_pos(argv) - 1);
	return (status);
}

/*
We execute at loop until proc argc -3  because argc -2 is the last one
and we have to redirect output to file and argc -1 is the output file
*/
int	main(int argc, char **argv, char **envp)
{
	t_fds	fds;
	t_env	env;
	int		status;

	if (argc >= 5)
	{
		fds.in = ft_file_open_input(argv);
		fds.out = ft_file_open_output(argv, argc);
		ft_fd_check(fds.in, fds.out);
		ft_fd_dups(fds.in, fds.out);
		env = ft_env_new(envp);
		status = ft_main_exec_cmds(argv, argc, fds, env);
		ft_main_free_resources(fds.in, fds.out, env, NULL);
		exit (status);
	}
	else
		ft_error_print_str_and_exit("Invalid number of arguments.", \
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;
	t_env	env;
	int		status;

	if (argc >= 5)
	{
		fdin = ft_file_open_input(argv);
		fdout = ft_file_open_output(argv, argc);
		ft_fd_check(fdin, fdout);
		ft_fd_dups(fdin, fdout);
		env = ft_env_new(envp);
		status = ft_main_execute_pipe(argv, env, \
					ft_main_get_first_cmd_pos(argv), argc - 2);
		if (status != 0)
		{
			ft_main_free_resources(fdin, fdout, env, argv[argc - 1]);
			exit(status);
		}
		status = ft_exec_redir_and_cmd(argv[argc - 2], env, fdout);
		if (status != 0)
		{
			ft_main_free_resources(fdin, fdout, env, argv[argc - 1]);
			exit(status);
		}
		status = ft_parent_get_last_child_status(argc - \
					ft_main_get_first_cmd_pos(argv) - 1);
		ft_main_free_resources(fdin, fdout, env, NULL);
		exit (status);
	}
	else
		ft_error_print_str_and_exit("Invalid number of arguments.", \
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
*/
