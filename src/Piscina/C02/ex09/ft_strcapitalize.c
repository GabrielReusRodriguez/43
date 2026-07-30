/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:08:56 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 15:11:06 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char str)
{
	if (str <= '9' && str >= '0')
		return (0);
	else
		return (-1);
}

int	ft_is_alphabetic(char str)
{
	if ((str >= 'a' && str <= 'z') \
		|| (str >= 'A' && str <= 'Z'))
	{
		return (0);
	}
	else
		return (-1);
}

char	*ft_revise_cases(char *str)
{
	char	*string;

	string = str;
	if (*string >= 'a' && *string <= 'z')
	{
		*string = *string - 32;
	}
	string++;
	while (*string != '\0' && (ft_is_alphabetic(*string) == 0 \
		|| ft_is_numeric(*string) == 0))
	{
		if (*string >= 'A' && *string <= 'Z')
		{
			*string = *string + 32;
		}
		string++;
	}
	return (string);
}

char	*ft_strcapitalize(char *str)
{
	char	*string;

	string = str;
	while (*string != '\0')
	{
		while (*string != '\0' && (ft_is_numeric(*string) != 0 \
			&& ft_is_alphabetic(*string) != 0))
		{
			string++;
		}
		string = ft_revise_cases(string);
		if (*string != '\0')
			string++;
	}
	return (str);
}
