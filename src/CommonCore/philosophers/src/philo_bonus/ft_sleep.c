/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:24:21 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/12 14:31:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_timestamp.h"

int	ft_sleep(unsigned long millisecs)
{
	return (usleep(millisecs * 1000));
}

int	ft_sleep_micro(unsigned long microsecs)
{
	return (usleep(microsecs));
}
