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

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

int	ft_strcmp_void(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_btree	*tree;
	char	*found;

	tree = ft_create_btree();
	found = (char *)btree_search_item(tree, "mucho", ft_strcmp_void);
	printf("search mucho: _%s_\n", found ? found : "(null)");
	found = (char *)btree_search_item(tree, "nope", ft_strcmp_void);
	printf("search nope: _%s_\n", found ? found : "(null)");
	return (0);
}
