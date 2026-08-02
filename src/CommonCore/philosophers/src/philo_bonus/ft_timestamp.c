/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:40:01 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 18:36:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>
#include "ft_timestamp.h"

/*
	if we look man gettimeofday, we see that tv_sec are seconds and 
	tv_usec are microseconds.
*/
t_timestamp	ft_timestamp_get(void)
{
	struct timeval	tv;
	t_timestamp		timestamp;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
	return (timestamp);
}
