/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:56:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/19 22:52:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "tokenizer/token.h"
#include "libft.h"

#include <stdio.h>

void	token_init(t_token *token, char *_text, t_token_type _type)
{
	token->text = _text;
	token->type = _type;
}

bool	token_new(t_token **token, char *_text, t_token_type _type)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (*token == NULL)
		return (ft_err_errno(NULL), false);
	token_init(*token, _text, _type);
	return (true);
}

void	token_destroy(t_token *token)
{
	if (token != NULL && token->text != NULL)
	{
		free (token->text);
		token->text = NULL;
	}
}

bool	token_new_list_node(t_list **node, t_token *token)
{
	*node = ft_lstnew(token);
	if (*node == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}