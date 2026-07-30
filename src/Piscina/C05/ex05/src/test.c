#include<stdio.h>
#include<string.h>

int	ft_sqrt(int nb);

int	main(void)
{
	int valor;
	//valor = INT_MAX;
	valor = 1119365;
	printf("SQRT %d es %d \n", valor, ft_sqrt(valor));
	return (0);
}
