/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:10:05 by greus-ro          #+#    #+#             */
/*   Updated: 2026/07/30 15:45:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*found;

	if (root == NULL)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found != NULL)
		return (found);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
