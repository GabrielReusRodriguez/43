#include<stdio.h>
#include<limits.h>
#include<unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(1234);
	write(1, "\n", 1);
	ft_putnbr(-1234);
	write(1, "\n", 1);
	ft_putnbr(INT_MAX);
	write(1, "\n", 1);
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
}
