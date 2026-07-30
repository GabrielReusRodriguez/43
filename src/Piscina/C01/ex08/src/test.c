#include<stdio.h>


#define SIZE 12

void print_array(int *tab,int size)
{
        printf("Valores del array : ");
        for(int i =0;i < size;i++)
        {
                printf("%d ",tab[i]);
        }
        printf("\n");
}

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int valores[SIZE] = {9,5,3,-8,7,1,10,4,-10,2,6,8};
	printf("ANTES ");
	print_array(valores,SIZE);
	ft_sort_int_tab(valores,SIZE);
	printf("DESPUES ");
	print_array(valores,SIZE);
}
