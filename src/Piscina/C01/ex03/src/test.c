#include<stdio.h>


void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{

	int x,y;
	int div,mod;
		
		
	x = 8;
	y = 5;
	div = 3;
	mod = 2;

	printf("Valores antes x: %d y : %d div : %d mod : %d \n",x,y,div,mod);
	ft_div_mod(x,y,&div,&mod);
	printf("Valores antes x: %d y : %d div : %d mod : %d \n",x,y,div,mod);

}
