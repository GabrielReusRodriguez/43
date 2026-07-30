#include<stdio.h>
#include<stdlib.h>

void ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int *********nbr;
	
	nbr = (int *********)	malloc(sizeof	(int ********));
	*nbr = (int ********)	malloc(sizeof	(int *******));
	**nbr = (int *******)	malloc(sizeof	(int ******));
	***nbr = (int ******)	malloc(sizeof	(int *****));
	****nbr = (int *****)	malloc(sizeof	(int ****));
	*****nbr = (int ****)	malloc(sizeof	(int ***));
	******nbr = (int ***)	malloc(sizeof	(int **));
	*******nbr = (int  **)	malloc(sizeof	(int *));
	********nbr = (int  *)	malloc(sizeof	(int ));
	
	*********nbr=67;

	printf("Valor antes %d\n",*********nbr);
	ft_ultimate_ft(nbr);
	printf("Valor antes %d\n",*********nbr);

	free(********nbr);
	free(*******nbr);
	free(******nbr);
	free(*****nbr);
	free(****nbr);
	free(***nbr);
	free(**nbr);
	free(*nbr);
	free(nbr);
	
	return (0);
}
