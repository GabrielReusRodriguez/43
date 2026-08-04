/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:38:21 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/28 14:24:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	ft_list_push_front(t_list **lst, t_list *new);

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

static t_list *create_node(const char *msg)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->content = (char *)msg;
	return (node);
}

static void	debug_list(t_list *lst)
{
	t_list	*node;
	node = lst;
	printf("DEBUG List****************************\n");
	if (node == NULL)
		printf("EMPTY\n");
	while (node != NULL)
	{
		printf("\tAddress: %p, content %p val: _%s_\n", node, node->content, (char *)node->content);
		node = node->next;
	}
	printf("END DEBUG List************************\n\n");
}

static void	clear_list(t_list **lst)
{
	t_list *node;
	t_list	*aux;
	
	node = *lst;
	while (node != NULL)
	{
		aux = node;
		node = node->next;
		free (aux);
	}
	*lst = NULL;
}


int main(void)
{

	{
		t_list	*list;
		t_list	*new;
		
		list = NULL;
		new = create_node("Hola mundo!");
		ft_list_push_front(&list, new);
		debug_list(list);
		clear_list(&list);
	}

	{
		t_list	*list;
		t_list	*new;
		
		list = NULL;
		new = create_node("Hola mundo!");
		ft_list_push_front(&list, new);
		new = create_node("Adios mundo!");
		ft_list_push_front(&list, new);
		debug_list(list);
		clear_list(&list);
	}


	return (0);
}