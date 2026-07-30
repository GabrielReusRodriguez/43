#include<stdio.h>


void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{

	int x,y;

	x = 8;
	y = 5;

	printf("Valores ANTES x : %d, y : %d \n",x,y);
	ft_ultimate_div_mod(&x,&y);
	printf("Valores ANTES x : %d, y : %d \n",x,y);
}
