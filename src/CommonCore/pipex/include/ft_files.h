/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:40:12 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/02 18:26:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# define INFILE 0
# define OUTFILE 1

int		ft_file_open(char *filename, int mode, const char *append_flag);
void	ft_file_close(int fdin, int fdout);

int		ft_file_open_output(char **argv, int argc);
int		ft_file_open_input(char **argv);

#endif