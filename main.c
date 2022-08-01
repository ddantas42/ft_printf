#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
  
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
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

char	*string_inverter(char *str)
{
	
}

char	*ft_put_hex(long int n)
{
	char	*str = malloc(16);
	int		len;
	char	c;
    float   resto;
	int		div;

	len = 0;
	if (!n)
		return (NULL);
	while (n > 15)
    {
		div = n / 16;
		resto = n % 16;
		str[len++] = tenths_to_hex(resto);
		n /= 16;
    }
	if (n > 0)
		str[len++] = tenths_to_hex(n);
	return (str);
}

int main()
{
	long int	n = -9223372036854775808;
	float   resto;
	float	div;

	while (n < 92233720368547758070)
	{
		printf("N = %ld | hex = %lx | My = %s\n", n, n, ft_put_hex(n));
		n++;
		delay(100);
	}
	return (0);
}