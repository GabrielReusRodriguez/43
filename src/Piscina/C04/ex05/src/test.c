#include<stdio.h>
#include<string.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char base[]= "a123456789";
	char msg[]="-a234";
	char msg1[]="a2314a45";

	printf("Valor _%s_ es %d\n",msg,ft_atoi_base(msg,base));
	printf("Valor _%s_ es %d\n",msg1,ft_atoi_base(msg1,base));
}
