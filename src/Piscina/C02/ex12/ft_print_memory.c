/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:37:22 by greus-ro          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define LOW_PRINTABLE 32
#define HIGH_PRINTABLE 126
#define BYTES_PER_LINE 16

static void	ft_uchar_2_hex(unsigned char value)
{
	char	digit;

	if (value < 16)
	{
		if (value < 10)
			digit = '0' + value;
		else
			digit = 'a' + (value -10);
		write(1, &digit, 1);
		return ;
	}
	ft_uchar_2_hex(value / 16);
	ft_uchar_2_hex(value % 16);
}

static unsigned int	ft_print_hex_content(void *memory, unsigned int num_bytes)
{
	unsigned char	*content;
	unsigned int	i;
	char			digit;

	i = 1;
	content = (unsigned char *)memory;
	while (i <= num_bytes)
	{
		if (content[i - 1] < 16)
		{
			write(1, "0", 1);
			if (content[i - 1] < 10)
				digit = '0' + content[i - 1];
			else
				digit = 'a' + (content[i - 1] - 10);
			write(1, &digit, 1);
		}
		else
			ft_uchar_2_hex(content[i - 1]);
		if (i % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	return (i);
}

static void	ft_print_content(void *memory, unsigned int num_bytes)
{
	unsigned char	*content;
	unsigned char	letter;
	unsigned int	i;

	i = 0;
	content = (unsigned char *)memory;
	while (i < num_bytes)
	{
		if (content[i] >= LOW_PRINTABLE && content[i] <= HIGH_PRINTABLE)
			letter = content[i];
		else
			letter = '.';
		write(1, &letter, 1);
		i++;
	}
}

static void	ft_print_address(unsigned long memory, int first_time)
{
	unsigned long	address;
	char			digit;
	unsigned long	long_number;

	address = memory;
	long_number = 0;
	while (first_time == 1 && memory != 0)
	{
		memory = memory >> 8;
		long_number++;
	}
	while (first_time == 1 && long_number++ < sizeof(unsigned long))
		write(1, "00", 2);
	if (address < 16)
	{
		if (address < 10)
			digit = '0' + address;
		else
			digit = 'a' + (address - 10);
		write(1, &digit, 1);
		return ;
	}
	ft_print_address(address / 16, 0);
	ft_print_address(address % 16, 0);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	num_bytes;
	unsigned int	bytes_written;

	i = 0;
	while (i < size)
	{
		num_bytes = BYTES_PER_LINE;
		if (size - i < BYTES_PER_LINE)
			num_bytes = size - i;
		ft_print_address((unsigned long)(addr + i), 1);
		write(1, ": ", 2);
		bytes_written = ft_print_hex_content(addr + i, num_bytes);
		while (bytes_written <= BYTES_PER_LINE)
		{
			write(1, "  ", 2);
			if (bytes_written % 2 == 0)
				write(1, " ", 1);
			bytes_written++;
		}
		ft_print_content(addr + i, num_bytes);
		write(1, "\n", 1);
		i = i + BYTES_PER_LINE;
	}
	return (addr);
}
