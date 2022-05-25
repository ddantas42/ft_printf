#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	n = -2;

	printf("-------------\n");
	while (n++ < 50)
		printf("%p | n = %d\n", n, n);
	printf("-------------\n");

	return(0);
}
