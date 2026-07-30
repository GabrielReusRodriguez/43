/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:38:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/03 22:02:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_error.h"
#include "ft_files.h"
//#include "ft_utils.h"
#include "ft_fd.h"
#include "libft.h"
#include "ft_get_next_line.h"

/*
	oflag = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	EQUALS 0644
*/
int	ft_file_open(char *filename, int mode, const char *append_flag)
{
	int	oflag;

	oflag = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (mode == INFILE)
	{
		if (access(filename, R_OK) == -1)
			return (-1);
		return (open(filename, O_RDONLY));
	}
	else
	{
		if (append_flag == NULL)
			return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, oflag));
		else
			return (open(filename, O_CREAT | O_WRONLY | O_APPEND, oflag));
	}
}

void	ft_file_close(int fdin, int fdout)
{
	if (fdin >= 0)
		close(fdin);
	if (fdout >= 0)
		close(fdout);
}

/*
	We compare with the length -1 because get_next_line returns the
	line \n and compares fails .
*/
static int	ft_file_read_stdin(char *delimiter)
{
	char	*line;
	int		initial_pipe[2];

	if (pipe(initial_pipe) < 0)
		return (-1);
	line = delimiter;
	while (line != NULL)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = ft_get_next_line_many_fds(STDIN_FILENO);
		if (line == NULL || \
				ft_strncmp(delimiter, line, ft_strlen(delimiter)) == 0)
			break ;
		ft_putstr_fd(line, initial_pipe[PIPE_WRITE_FD]);
		free(line);
	}
	if (line != NULL)
		free(line);
	close(initial_pipe[PIPE_WRITE_FD]);
	return (initial_pipe[PIPE_READ_FD]);
}

int	ft_file_open_input(char **argv)
{
	int		fdin;
	char	*delimiter;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		delimiter = ft_strjoin(argv[2], "\n");
		fdin = ft_file_read_stdin(delimiter);
		free (delimiter);
	}
	else
		fdin = ft_file_open(argv[1], INFILE, NULL);
	return (fdin);
}

int	ft_file_open_output(char **argv, int argc)
{
	int		fdout;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		fdout = ft_file_open(argv[argc - 1], OUTFILE, argv[1]);
	else
		fdout = ft_file_open(argv[argc - 1], OUTFILE, NULL);
	return (fdout);
}
