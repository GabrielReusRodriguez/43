/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:05:06 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/01 14:29:40 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_btree.h"

t_btree	*btree_create_node(void *item);

char	*ft_strdup(char *ptr)
{
	int		size;
	int		i;
	char	*dup;

	size = 0;
	while (ptr[size] != '\0')
	{
		size++;
	}
	dup = (char *)malloc((size + 1));
	i = 0;
	while (i < size)
	{
		dup[i] = ptr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_btree	*ft_create_btree(void)
{
	t_btree		*root;
	t_btree		*new_node;

	new_node = NULL;
	root = btree_create_node(ft_strdup("Gabriel"));

	new_node = btree_create_node(ft_strdup("Reus"));
	root->left = new_node;

	new_node = btree_create_node(ft_strdup("Rodriguez"));
	root->right = new_node;

	new_node = btree_create_node(ft_strdup("merece"));
	root->left->left = new_node;

	new_node = btree_create_node(ft_strdup("mucho"));
	root->left->right = new_node;

	new_node = btree_create_node(ft_strdup("mas"));
	root->right->left = new_node;

	return (root);
}

void	ft_print_tree_preorder(t_btree *root)
{
	t_btree	*node;
	
	node = root;
	printf("\tItem: _%s_\n",(char *)root->item);
	if (node->left != NULL)
		ft_print_tree_preorder(node->left);
	if (node->right != NULL)
		ft_print_tree_preorder(node->right);
}

void	ft_print_tree_inorder(t_btree *root)
{
	t_btree	*node;
	
	node = root;
	if (node->left != NULL)
		ft_print_tree_inorder(node->left);
	printf("\tItem: _%s_\n",(char *)root->item);
	if (node->right != NULL)
		ft_print_tree_inorder(node->right);
}

void	ft_print_tree_postorder(t_btree *root)
{
	t_btree	*node;
	
	node = root;
	if (node->left != NULL)
		ft_print_tree_postorder(node->left);
	if (node->right != NULL)
		ft_print_tree_postorder(node->right);
	printf("\tItem: _%s_\n",(char *)root->item);
}

int	main(void)
{
	t_btree		*tree;

	tree = ft_create_btree();
	printf("Arbol init\n");
	ft_print_tree_preorder(tree);
	return (0);
}
