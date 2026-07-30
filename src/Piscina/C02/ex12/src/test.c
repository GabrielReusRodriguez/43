#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_print_memory(void *memory,unsigned int size);

int main(void)
{
	
	char msg1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus et lorem sed orci lobortis integer.";
	ft_print_memory(msg1,80);
	

	char src[0xFF + 10];
	int	i;

	i = 0;
	while (i <= 0xFF)
	{
		src[i] = i;
		i++;
	}
	src[i] = 0;

	i = 0;
	while (i < 30)
	{
		ft_print_memory((void *)src, i);
		i++;
	}

	ft_print_memory((void *)src, 0x101);

/*
	char msg1[] = "";
	ft_print_memory(msg1,1);
*/
	return (0);

}