/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:47:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 22:32:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>

typedef struct s_stack{
	void				*content;
	struct s_stack		*next;
}	t_stack;

void		ft_stack_push(t_stack **stack, t_stack *node);
t_stack		*ft_stack_pop(t_stack **stack);
size_t		ft_stack_size(const t_stack *stack);
int			ft_stack_isempty(t_stack **stack);
t_stack		*ft_stack_newnode(void *content);
void		ft_stack_clear(t_stack **stack, void (*fr) (void *) );
void		ft_stack_debug(const t_stack *stack);


#endif