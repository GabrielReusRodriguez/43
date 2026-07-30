#include<stdio.h>


void	ft_swap(int *a, int *b);

int	main(void)
{

	int x,y;

	x = 1;
	y = 4;

	printf("Valor antes de SWAP x:%d  y: %d \n",x,y);
	ft_swap(&x,&y);
	printf("Valor despues de SWAP x: %d  y: %d  \n",x,y);

}
