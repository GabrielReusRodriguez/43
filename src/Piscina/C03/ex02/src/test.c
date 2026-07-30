#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	a1[64] = "Hola";
	char	a2[] = " Mundo";
	char	b1[64] = "Hola";
	char	b2[] = " Mundo";

	char	c1[64] = "Foo";
	char	c2[] = "Bar";
	char	d1[64] = "Foo";
	char	d2[] = "Bar";

	printf("STRING.h: %s\n", strcat(a1, a2));
	printf("ft_strcat: %s\n", ft_strcat(b1, b2));
	printf("STRING.h: %s\n", strcat(c1, c2));
	printf("ft_strcat: %s\n", ft_strcat(d1, d2));
	return (0);
}
