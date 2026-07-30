/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:10:47 by greus-ro          #+#    #+#             */
/*   Updated: 2026/07/30 15:45:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_btree.h"

typedef struct s_level_ctx
{
	void	(*applyf)(void *item, int current_level, int is_first_elem);
	int		level;
	int		is_first;
}	t_level_ctx;

static int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (root == NULL)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

static void	btree_apply_level(t_btree *root, int current, t_level_ctx *ctx)
{
	if (root == NULL)
		return ;
	if (current == ctx->level)
	{
		ctx->applyf(root->item, ctx->level, ctx->is_first);
		ctx->is_first = 0;
		return ;
	}
	btree_apply_level(root->left, current + 1, ctx);
	btree_apply_level(root->right, current + 1, ctx);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int			level;
	int			max_level;
	t_level_ctx	ctx;

	if (root == NULL)
		return ;
	max_level = btree_level_count(root);
	level = 0;
	ctx.applyf = applyf;
	while (level < max_level)
	{
		ctx.level = level;
		ctx.is_first = 1;
		btree_apply_level(root, 0, &ctx);
		level++;
	}
}
