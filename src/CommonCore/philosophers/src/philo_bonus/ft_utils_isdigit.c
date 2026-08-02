/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:26:44 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 18:34:47 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_bool	ft_utils_isdigit(char character)
{
	if (character >= '0' && character <= '9')
		return (TRUE);
	return (FALSE);
}
