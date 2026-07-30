#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void	ft_memset(char *ptr)
{
	unsigned int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		ptr[i] = '\0';
		i++;
	}
}

int main(void)
{/*
	char msg1[] ="";
	char msg2[] ="  FDF";
	char msg3[] ="Gabriel Reus Rodriguez"; 
	char msg4[] ="Gregorio Reus Rodriguez";
	*/
	char msg5[] = "World!";
	char msg6[] = "Hello, World!";
	char msg7[] = "";
	/*
	char msg8[] = "Hell";
	char msg9[] = "Hello, World!";
	char msg9[] = "Hello, World!";
	*/
	char *res;
	char *res_ft;
	int		size;
	int		size_ft;

	res = (char *)malloc(BUFFER_SIZE);
	if ( res == NULL)
	{
		return (1);
	}

	res_ft = (char *)malloc(BUFFER_SIZE);
	if ( res_ft == NULL)
	{
		return (1);
	}


	ft_memset(res);
	ft_memset(res_ft);
	size = strlcpy(res, msg5,10);
	size_ft = ft_strlcpy(res_ft,msg5,10);
	printf("Src %s strlcpy %s ft_strlcpy %s cmp %d size %d size ft %d \n",msg5,res,res_ft,strcmp(res,res_ft),size, size_ft);
	
	ft_memset(res);
	ft_memset(res_ft);
	size = strlcpy(res, msg6,10);
	size_ft = ft_strlcpy(res_ft,msg6,10);
	printf("Src %s strlcpy %s ft_strlcpy %s cmp %d size %d size ft %d \n",msg6,res,res_ft,strcmp(res,res_ft),size, size_ft);

	
	ft_memset(res);
	ft_memset(res_ft);
	size = strlcpy(res, msg6,5);
	size_ft = ft_strlcpy(res_ft,msg6,5);
	printf("Src %s strlcpy %s ft_strlcpy %s cmp %d size %d size ft %d \n",msg6,res,res_ft,strcmp(res,res_ft),size, size_ft);
	
	ft_memset(res);
	ft_memset(res_ft);
	size = strlcpy(res, msg7,1);
	size_ft = ft_strlcpy(res_ft,msg7,1);
	printf("Src %s strlcpy %s ft_strlcpy %s cmp %d size %d size ft %d \n",msg7,res,res_ft,strcmp(res,res_ft),size, size_ft);
	
	ft_memset(res);
	ft_memset(res_ft);
	size = strlcpy(res, msg6,1);
	size_ft = ft_strlcpy(res_ft,msg6,1);
	printf("Src %s strlcpy %s ft_strlcpy %s cmp %d size %d size ft %d \n",msg6,res,res_ft,strcmp(res,res_ft),size, size_ft);

	return (0);

}