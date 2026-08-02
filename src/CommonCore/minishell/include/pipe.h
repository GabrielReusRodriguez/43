/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:32:55 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 19:14:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <stdbool.h>

typedef struct s_pipe
{
	int	read;
	int	write;
}	t_pipe;

//file/pipes.c
t_pipe	pipe_new(void);
bool	pipe_open(t_pipe *my_pipe);
bool	pipe_close(t_pipe *my_pipe);

#endif