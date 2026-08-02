/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_BONUS.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:16:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/02 22:50:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BFS_BONUS_H
# define FT_BFS_BONUS_H

# include "ft_game_bonus.h"

typedef struct s_bfs_node
{
	int				x;
	int				y;
	unsigned char	type;
}	t_bfs_node;

t_bool	ft_bfs(t_game *game);
t_list	*ft_bfs_create_node(int x, int y, char type);
void	ft_bfs_destroy(t_list **visit, t_list **unvisit);
t_list	*ft_bfs_dequeue(t_list **list);
void	ft_lstremoveitem(t_list **list, t_bfs_node *node_2_rem);
t_list	*ft_bfs_find(t_list *list, int x, int y);

#endif