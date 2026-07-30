#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void ft_strcpy(char *dest, char *src);

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
	strcpy(res,msg1);
	ft_strcpy(res_ft,msg1);
	printf("Src %s srtcpy %s ft_strcpy %s cmp %d\n",msg2,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strcpy(res,msg2);
	ft_strcpy(res_ft,msg2);
	printf("Src %s srtcpy %s ft_strcpy %s cmp %d\n",msg2,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strcpy(res,msg3);
	ft_strcpy(res_ft,msg3);
	printf("Src %s srtcpy %s ft_strcpy %s cmp %d\n",msg3,res, res_ft,strcmp(res,res_ft));

	memset(res,'\0',BUFFER_SIZE);
	memset(res_ft,'\0',BUFFER_SIZE);
	strcpy(res,msg4);
	ft_strcpy(res_ft,msg4);
	printf("Src %s srtcpy %s ft_strcpy %s cmp %d\n",msg4,res, res_ft,strcmp(res,res_ft));

	return (0);

}