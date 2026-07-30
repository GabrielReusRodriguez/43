#include<stdio.h>

void print_array(int *tab,int size)
{
	printf("Valores del array : ");
	for(int i =0;i < size;i++)
	{
		printf("%d ",tab[i]);
	}
	printf("\n");
}

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int tab[3];
	int size = 3;
	int tab1[4];
	int size1 = 4;

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;


	tab1[0] = 1;
	tab1[1] = 2;
	tab1[2] = 3;
	tab1[3] = 4;


	printf("ANTES\n\n");
	print_array(tab,size);
	print_array(tab1,size1);

	ft_rev_int_tab(tab,size);
	ft_rev_int_tab(tab1,size1);
	
	printf("ANTES\n\n");
	print_array(tab,size);
	print_array(tab1,size1);


}
