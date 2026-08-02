/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:49:29 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 22:13:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>
# include "libft.h"

typedef enum e_token_type
{
	TOKEN_TYPE_NONE,
	TOKEN_TYPE_WORD,
	TOKEN_TYPE_DQUOTE,
	TOKEN_TYPE_SQUOTE,
	TOKEN_TYPE_PIPE,
	TOKEN_TYPE_REDIR,
	TOKEN_TYPE_SEMICOLON

}	t_token_type;

typedef struct s_token
{
	char			*text;
	t_token_type	type;
} t_token;

void	token_init(t_token *token, char *_text, t_token_type _type);
bool	token_new(t_token **token, char *_text, t_token_type _type);
void	token_destroy(t_token *token);
bool	token_new_list_node(t_list **node, t_token *token);

#endif