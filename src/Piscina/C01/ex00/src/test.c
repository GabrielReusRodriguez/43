#include<stdio.h>

void	ft_ft(int *c);

int	main(void)
{
	int x = 0;
	int y =-100;
	int z = 900;

	printf("Valores originales x: %d y: %d z: %d \n",x,y,z);
	ft_ft(&x);
	ft_ft(&y);
	ft_ft(&z);
	printf("Valores procesados x: %d y: %d z: %d \n",x,y,z);

}
