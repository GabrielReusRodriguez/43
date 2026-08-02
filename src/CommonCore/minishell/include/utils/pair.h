/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:22:26 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 15:36:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

# include <stdbool.h>

typedef struct s_pair
{
	char	*key;
	char	*value;

} t_pair;

t_pair	pair_new();
bool	pair_init(t_pair *pair, const char *_key, const char *_value);
bool	pair_update(t_pair *pair, const char *_key, const char *_value);
void	pair_destroy(t_pair *pair);
void	pair_free_node(void *);

#endif