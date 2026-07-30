#include<stdio.h>
#include<string.h>

int	ft_strncmp(char *s1,char*s2,unsigned int n);

int	main(void)
{
	char	mensaje1[] = "Hola";
	char	mensaje2[] = "Hola";

	char	mensaje3[] = "Hola Adoios";
	char	mensaje4[] = "Hola";

	char	mensaje5[] = "Hola";
	char	mensaje6[] = "Hola Adios";

	char	mensaje7[] = "";
	char	mensaje8[] = "Hola";

	printf(" STRING.h Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,strncmp(mensaje1,mensaje2,3));
	printf("          Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,ft_strncmp(mensaje1, mensaje2,3));

	printf(" STRING.h Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,strncmp(mensaje3,mensaje4,3));
	printf("          Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,ft_strncmp(mensaje3, mensaje4,3));


	printf(" STRING.h Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,strncmp(mensaje5,mensaje6,4));
	printf("          Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,ft_strncmp(mensaje5, mensaje6,4));


	printf(" STRING.h Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,strncmp(mensaje7,mensaje8,3));
	printf("          Msg a: %s _  msg b = %s _ comp = %d \n",mensaje1,mensaje2,ft_strncmp(mensaje7, mensaje8,3));


}
