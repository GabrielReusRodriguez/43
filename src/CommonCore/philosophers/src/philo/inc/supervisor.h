/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:55:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/22 23:44:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERVISOR_H
# define SUPERVISOR_H

# include <stdbool.h>
# include "simulation.h"

# define SUPERVISOR_SLEEP_USECS 500

bool	supervisor_checks(t_simulation *simulation);

#endif