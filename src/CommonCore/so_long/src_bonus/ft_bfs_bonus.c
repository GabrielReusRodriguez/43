/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:05:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/05 18:16:16 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_geometry2d_bonus.h"
#include "ft_bfs_bonus.h"
#include "libft.h"

static t_bool	ft_bfs_add_vecino(t_list **list, t_map *map, \
					t_point2d position)
{
	t_list	*vecino;
	char	type;

	if (position.x < 1 || position.y < 1 || position.x > (int)map->width || \
			position.y > (int)map->height)
		return (TRUE);
	type = map->ber_map[position.y][position.x];
	if (type == WALL || type == ENEMY)
		return (TRUE);
	vecino = ft_bfs_create_node(position.x, position.y, type);
	if (vecino == NULL)
	{
		ft_lstclear(list, &free);
		return (FALSE);
	}
	else
		ft_lstadd_back(list, vecino);
	return (TRUE);
}

static t_list	*ft_bfs_get_vecinos(t_map	*map, t_bfs_node *node)
{
	t_list		*list_vecinos;
	t_point2d	pos;

	list_vecinos = NULL;
	pos = ft_point2d_new(node->x + 1, node->y);
	if (ft_bfs_add_vecino(&list_vecinos, map, pos) == FALSE)
		return (NULL);
	pos = ft_point2d_new(node->x - 1, node->y);
	if (ft_bfs_add_vecino(&list_vecinos, map, pos) == FALSE)
		return (NULL);
	pos = ft_point2d_new(node->x, node->y + 1);
	if (ft_bfs_add_vecino(&list_vecinos, map, pos) == FALSE)
		return (NULL);
	pos = ft_point2d_new(node->x, node->y - 1);
	if (ft_bfs_add_vecino(&list_vecinos, map, pos) == FALSE)
		return (NULL);
	return (list_vecinos);
}

static t_bool	ft_bfs_explore(t_map *map, t_list *node, t_list **visit, \
				t_list **unvisit)
{
	t_bfs_node	*b_node;
	t_list		*vecinos;
	t_list		*vecino;

	b_node = (t_bfs_node *)node->content;
	vecinos = ft_bfs_get_vecinos(map, b_node);
	if (vecinos == NULL)
		return (FALSE);
	while (vecinos != NULL)
	{
		vecino = vecinos;
		vecinos = vecinos->next;
		vecino->next = NULL;
		b_node = (t_bfs_node *)vecino->content;
		if (ft_bfs_find(*visit, b_node->x, b_node->y) == NULL)
			ft_lstadd_front(unvisit, vecino);
		else
			ft_lstdelone(vecino, &free);
	}
	ft_lstclear(&vecinos, &free);
	return (TRUE);
}

/*
		Breadth-first search Algorithm invented by  Konrad Zuse in 1945
//https://en.wikipedia.org/wiki/Breadth-first_search
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as explored
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as explored then
11                  label w as explored
12                  w.parent := v
13                  Q.enqueue(w)		
*/

static t_bool	ft_bfs_exists_path(t_game *game, \
					t_list **unvisited, t_list **visited)
{
	t_bfs_node	*bfs_node;
	t_list		*node;

	while (ft_lstsize(*unvisited) > 0)
	{
		node = ft_bfs_dequeue(unvisited);
		bfs_node = (t_bfs_node *)node->content;
		if (bfs_node->type == EXIT)
		{
			ft_lstdelone(node, &free);
			ft_bfs_destroy(visited, unvisited);
			return (TRUE);
		}
		if (ft_bfs_explore(game->map, node, visited, unvisited) == FALSE)
		{
			ft_lstdelone(node, &free);
			ft_bfs_destroy(visited, unvisited);
			return (FALSE);
		}
		ft_lstadd_front(visited, node);
	}
	ft_bfs_destroy(visited, unvisited);
	return (FALSE);
}

t_bool	ft_bfs(t_game *game)
{
	t_list		*unvisited;
	t_list		*visited;
	t_list		*node;

	visited = NULL;
	unvisited = NULL;
	node = ft_bfs_create_node(game->player.position.x, \
				game->player.position.y, PLAYER);
	if (node == NULL)
		return (FALSE);
	ft_lstadd_front(&unvisited, node);
	return (ft_bfs_exists_path(game, &unvisited, &visited));
}
