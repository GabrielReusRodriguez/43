#include<stdio.h>
#include<string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{

	char	*msg;
	//char	number[] = "100";
	char	base_from[] = "0123456789";
	char	base_to[] = "0123456789ABCDEF";
	char	base_to_oct[] = "01234567";

	if (argc != 2)
	{
		printf("ERROR en argumentos\n");
		return (1);
	}
	msg = ft_convert_base(argv[1], base_from,base_to);
	printf("Valor en nueva base es: %s\n",msg);
	msg = ft_convert_base(argv[1], base_from,base_to_oct);
	printf("Valor en nueva base es: %s\n",msg);

	return (0);


}
