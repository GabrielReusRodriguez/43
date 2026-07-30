/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:29:02 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/08 12:58:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_arithmetic.h"
#include "ft_atoi.h"
#include "ft_put.h"

typedef struct s_function{
	char	operation;
	int		(*function)(int, int);
}	t_function;

void	ft_add_function(t_function *functions, char symbol, int (*f)(int, int))
{
	functions->operation = symbol;
	functions->function = f;
}

void	ft_init_function_table(t_function *functions)
{
	ft_add_function(functions + 0, '+', add);
	ft_add_function(functions + 1, '-', substract);
	ft_add_function(functions + 2, '/', divide);
	ft_add_function(functions + 3, '%', mod);
	ft_add_function(functions + 4, '*', multiply);
}

t_function	*ft_search_function(t_function *functions, char op)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (functions[i].operation == op)
			return (functions + i);
		i++;
	}
	return (NULL);
}

void	ft_parse_op(t_function *functions, char **argv)
{
	int			value1;
	int			value2;
	int			result;
	char		*op;
	t_function	*f;

	value1 = ft_atoi(argv[1]);
	op = argv[2];
	value2 = ft_atoi(argv[3]);
	if (value2 == 0 && ((*op == '/') || (*op == '%')))
	{
		if (*op == '/')
			ft_putline("Stop : division by zero");
		if (*op == '%')
			ft_putline("Stop : modulo by zero");
		return ;
	}
	f = ft_search_function(functions, *op);
	if (f == NULL)
		result = 0;
	else
		result = (*f->function)(value1, value2);
	ft_putnbr(result);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_function	*functions;

	if (argc != 4)
		return (1);
	functions = (t_function *)malloc(5 * sizeof(t_function));
	if (functions == NULL)
		return (0);
	ft_init_function_table(functions);
	ft_parse_op(functions, argv);
}
