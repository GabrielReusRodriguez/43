/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:27:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/12/21 21:27:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H


# include <stdbool.h>

typedef struct s_str_fragment
{
	int begin;
	int end;
} t_str_fragment;

bool			utils_string_unquote(const char *original, char **unquoted);
bool			utils_str_join_compontents(const char *hdr, const char *body, \
					const char *tail, char **final);
t_str_fragment	utils_new_str_fragment(void);

//utils/str_appends.c
bool			utils_dchar_append_back(char ***vector, char *new_str);
bool			utils_dchar_append_front(char ***vector, char *new_str);


#endif