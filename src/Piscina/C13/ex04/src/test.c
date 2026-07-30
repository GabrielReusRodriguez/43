#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (node == NULL)
		return (NULL);
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

char	*ft_strdup(char *ptr)
{
	int		size;
	int		i;
	char	*dup;

	size = 0;
	while (ptr[size] != '\0')
		size++;
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
	t_btree	*root;
	t_btree	*new_node;

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

void	ft_print_item(void *data)
{
	printf("\tItem: _%s_\n", (char *)data);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

int	ft_strcmp_void(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

void	ft_print_tree_inorder(t_btree *root)
{
	if (root == NULL)
		return ;
	ft_print_tree_inorder(root->left);
	printf("\tItem: _%s_\n", (char *)root->item);
	ft_print_tree_inorder(root->right);
}

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, ft_strdup("m"), ft_strcmp_void);
	btree_insert_data(&root, ft_strdup("a"), ft_strcmp_void);
	btree_insert_data(&root, ft_strdup("z"), ft_strcmp_void);
	btree_insert_data(&root, ft_strdup("c"), ft_strcmp_void);
	printf("BST inorder:\n");
	ft_print_tree_inorder(root);
	return (0);
}
