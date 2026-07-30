#include<stdio.h>
#include<string.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char 	**split;
	int		i;

	i = 0;
	split =  ft_split(",,hello,world,,",",");
	while(split[i] != NULL)
	{
		printf("TOKEN: _%s_\n",split[i]);
		i++;
	}
	if(split[i] == NULL)
	{
		printf("Marca final\n");
	}
	
	i = 0;
	split =  ft_split(",,",",");
	while(split[i] != NULL)
	{
		printf("TOKEN: _%s_\n",split[i]);
		i++;
	}
	if(split[i] == NULL)
	{
		printf("Marca final\n");
	}
	
	i = 0;
	split =  ft_split("",",");
	while(split[i] != NULL)
	{
		printf("TOKEN: _%s_\n",split[i]);
		i++;
	}
	if(split[i] == NULL)
	{
		printf("Marca final\n");
	}

	i = 0;
	split =  ft_split(",,","");
	while(split[i] != NULL)
	{
		printf("TOKEN: _%s_\n",split[i]);
		i++;
	}
	if(split[i] == NULL)
	{
		printf("Marca final\n");
	}

	return (0);

}
