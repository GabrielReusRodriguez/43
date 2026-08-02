/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_utilities_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:05:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:07 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Breadth-first search */
#include <stdlib.h>
#include "ft_bfs_bonus.h"
#include "libft.h"

t_list	*ft_bfs_dequeue(t_list **list)
{
	t_list	*node;

	if (list == NULL)
		return (NULL);
	node = *list;
	*list = node->next;
	node->next = NULL;
	return (node);
}

t_list	*ft_bfs_create_node(int x, int y, char type)
{
	t_list		*list_node;
	t_bfs_node	*node;

	node = (t_bfs_node *)malloc(sizeof(t_bfs_node));
	if (node == NULL)
		return (NULL);
	node->x = x;
	node->y = y;
	node->type = type;
	list_node = ft_lstnew(node);
	if (list_node == NULL)
		free (node);
	return (list_node);
}

void	ft_bfs_destroy(t_list **visit, t_list **unvisit)
{
	ft_lstclear(visit, &free);
	ft_lstclear(unvisit, &free);
}

t_list	*ft_bfs_find(t_list *list, int x, int y)
{
	t_list		*l_node;
	t_bfs_node	*b_node;

	l_node = list;
	while (l_node != NULL)
	{
		b_node = (t_bfs_node *)l_node->content;
		if (b_node->x == x && b_node->y == y)
			return (l_node);
		l_node = l_node->next;
	}
	return (NULL);
}

void	ft_lstremoveitem(t_list **list, t_bfs_node *node_2_rem)
{
	t_list		*node;
	t_list		*prev;
	t_list		*next;
	t_bfs_node	*b_node;

	if (list == NULL || *list == NULL || node_2_rem == NULL)
		return ;
	node = *list;
	prev = NULL;
	while (node != NULL)
	{
		b_node = (t_bfs_node *)node->content;
		if (b_node->x == node_2_rem->x && b_node->y == node_2_rem->y)
		{
			next = node->next;
			ft_lstdelone(node, &free);
			if (prev == NULL)
				*list = node;
			else
				prev->next = next;
			return ;
		}
		prev = node;
		node = node->next;
	}
}
