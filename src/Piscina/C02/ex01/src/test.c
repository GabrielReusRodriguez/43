#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void ft_strncpy(char *dest, char *src,int n);

int main(void)
{
	char msg1[] ="";
	char msg2[] ="  FDF";
	char msg3[] ="Gabriel Reus Rodriguez"; 
	char msg4[] ="Gregorio Reus Rodriguez";
	char *res;
	char *res_ft;

	res = (char *)malloc(BUFFER_SIZE);
	if (res == NULL)
	{
		return (1);
	}
	res_ft = (char *)malloc(BUFFER_SIZE);
	if (res_ft == NULL)
	{
		return (1);
	}

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strncpy(res,msg1,4);
	ft_strncpy(res_ft,msg1,4);
	printf("Src %s strncpy %s ft_strncpy %s cmp %d\n",msg2,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strncpy(res,msg2,3);
	ft_strncpy(res_ft,msg2,3);
	printf("Src %s strncpy %s ft_strncpy %s cmp %d\n",msg2,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strncpy(res,msg3,100);
	ft_strncpy(res_ft,msg3,100);
	printf("Src %s strncpy %s ft_strncpy %s cmp %d\n",msg3,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strncpy(res,msg4,1);
	ft_strncpy(res_ft,msg4,1);
	printf("Src %s strncpy %s ft_strncpy %s cmp %d\n",msg4,res, res_ft,strcmp(res,res_ft));

	return (0);

}