#include "ft_printf.h"
#include <stdio.h>

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*letters_hex(int n)
{
	if (n == 10)
		return ("a");
	if (n == 11)
		return ("b");
	if (n == 12)
		return ("c");
	if (n == 13)
		return ("d");
	if (n == 14)
		return ("e");
	if (n == 15)
		return ("f");
}

char	tenths_to_hex(int n)
{
	if (n < 10)
		return ((char)(n + 48));
	if (n >= 10)
		return ((char)(n + 87));
	return (0);
}

void	*ft_put_hex(long int n)
{
	char	c;
    float   resto;
	int		div;

    while(n > 15)
    {
		div = n / 16;
		resto = n % 16;
		c = tenths_to_hex(resto);
		write(1, &c, 1);
		n /= 16;
    }
	if (n > 0)
	{
		c = tenths_to_hex(n);
		write(1, &c, 1);
	}
}

int main()
{
	long int	n = 2000;
	float   resto;
	float	div;
	

	// while (n <= 100)
	// {
	// 	printf("Printf ! Hex = %x | n = = malloc(2);
	// }

	printf(" = my | N = %ld | hex = %lx", n, n);
	ft_put_hex(n);
	printf(" \n");


	return (0);
}