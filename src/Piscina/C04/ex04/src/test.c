#include<stdio.h>
#include<string.h>

int	ft_putnbr_base(int nb, char *base);

int	main(void)
{
    ft_putnbr_base(8,"01");
	printf("\n");
	ft_putnbr_base(0,"01");
	printf("\n");
	ft_putnbr_base(42,"0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(42,"poniguay");
	printf("\n");
	ft_putnbr_base(42,"\v0123456789abcdef");
	printf("\n");

}
