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

void	btree_apply_infix(t_btree *root, void (*applyf)(void *));

int	main(void)
{
	t_btree	*tree;

	tree = ft_create_btree();
	printf("Infix:\n");
	btree_apply_infix(tree, ft_print_item);
	return (0);
}
