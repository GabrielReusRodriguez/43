#include<stdio.h>


int	ft_strlen(char *str);

int	main(void)
{
	char mensaje1[] = "Hola mundo!";
	char mensaje2[] = "Gabriel Reus";

	int size1,size2;

	size1 = ft_strlen(mensaje1);
	size2 = ft_strlen(mensaje2);

	printf("String %s Tamano %d \n",mensaje1,size1);
	printf("String %s Tamano %d \n",mensaje2,size2);
}
