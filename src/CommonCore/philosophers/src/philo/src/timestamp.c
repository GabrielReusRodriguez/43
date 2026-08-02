/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:23:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/18 23:29:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <sys/time.h>

#include "datatypes.h"

/*
	tv.sec are the seconds of day
	tv.usec are the microseconds of day (to get milliseconds we can divide 
	by 1000)
*/
bool	get_timestamp(t_milisecs *milisecs)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL) < 0)
		return (false);
	*milisecs = (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
	return (true);
}
