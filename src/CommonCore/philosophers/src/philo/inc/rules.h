/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:56:01 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/19 21:07:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H

#define RULES_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_rules
{
	size_t	number_of_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_meals;
	
}	t_rules;

bool	rules_import_args(int argc, char **argv, t_rules *rules);

#endif
