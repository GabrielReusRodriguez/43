#include<stdio.h>


void	ft_is_negative(int n);

int	main(void)
{
	int in = -1;
	int iz = 0;
	int ip = 8;\

	printf(" Int: %d \n",in);
	ft_is_negative(in);
	printf(" Int: %d \n",iz);
	ft_is_negative(iz);
	printf(" Int: %d \n",ip);
	ft_is_negative(ip);

}
