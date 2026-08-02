/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fragment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:30:57 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 19:34:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/string.h"

t_str_fragment	utils_new_str_fragment(void)
{
	t_str_fragment	fragment;
	
	fragment.begin = 0;
	fragment.end = 0;
	return (fragment);
}
