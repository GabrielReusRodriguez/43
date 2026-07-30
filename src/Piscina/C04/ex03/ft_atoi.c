/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:53 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/01 20:39:03 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_get_sign(char **str)
{
	int	num_minus;

	num_minus = 0;
	while (**str == '-' || **str == '+')
	{
		if ((**str) == '-')
		{
			num_minus++;
		}
		(*str)++;
	}
	if (num_minus % 2 == 1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	ft_atoi(char *str)
{
	int					num;
	char				*str_num;
	int					signo;
	int					digit;

	num = 0;
	str_num = str;
	while (*str_num == ' ' || *str_num == '\t' || *str_num == '\v'\
		|| *str_num == '\r' || *str_num == '\n' || *str_num == '\f')
	{
		str_num++;
	}
	signo = ft_get_sign(&str_num);
	while (*str_num >= '0' && *str_num <= '9')
	{
		digit = *str_num - '0';
		num = num * 10 + digit;
		str_num++;
	}
	return (signo * num);
}

/*
int	main(void)
{
	
	char msg1[] = "\t\n\v\f\r      23";
	int v1 =ft_atoi(msg1);
	printf("Valor %s, atoi %d\n ",msg1,v1);

	char msg2[] = "0";
	int v2 = ft_atoi(msg2);
	printf("Valor %s, atoi %d\n ",msg2,v2);

	char msg3[] = "-42";
	int v3 = ft_atoi(msg3);
	printf("Valor %s, atoi %d\n ",msg3,v3);

	char msg4[] = "--42";
	int v4 = ft_atoi(msg4);
	printf("Valor %s, atoi %d\n ",msg4,v4);
	
	char msg5[] = "-+-42";
	printf("Valor %s, atoi %d\n ",msg5,ft_atoi(msg5));
	
	char msg6[] = "-+42";
	printf("Valor %s, atoi %d\n ",msg6,ft_atoi(msg6));

	char msg7[] = "23";
	printf("Valor %s, atoi %d\n ",msg7,ft_atoi(msg7));

}
*/
