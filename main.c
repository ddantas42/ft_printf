//#include "ft_printf.h"
#include <stdio.h>

/*int	ft_put_hex(float n)
{
    char    *str;
    float   rest;

    rest = n;

    while (n > 0)
    {
        n /= 16;
    }

    return (rest);
}*/

/*int main()
{
	int	n = -1;

	printf("-------------\n");
	while (n++ < 50)
		printf("%x | n = %d\n", n, n);
	printf("-------------\n");

	return(0);
}
*/

int main()
{
	int	n = 0;

	while (n <= 100)
	{
		printf("Hex = %x | n = %d\n", n, n);
		n++;
	}
	return (0);
}