#include<stdio.h>

int	ft_ten_queens_puzzle(void);

int	main(void)
{
    int num_solutions;

    num_solutions = 0;
	num_solutions = ft_ten_queens_puzzle();
    printf("TOTAL solutions : %d\n",num_solutions);
}
