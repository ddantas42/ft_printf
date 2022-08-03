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
		return (n + 48);
	if (n >= 10)
		return (n + 87);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

// char	*string_inverter(char *str, int len)
// {
// 	int		n;
// 	char	*nova = malloc((len + 1) * sizeof(char));

// 	n = 0;
// 	while (len)
// 		str[len--] = nova[n++];
// 	nova[++n] = '\0';
// 	free(str);
// 	return (nova);
// }

// char	*ft_put_hex(long int n)
// {
// 	char	*str = malloc(16);
// 	int		len;
// 	char	c;

// 	len = 0;
// 	if (n < 0)
// 		return ("0");
// 	while (n > 15)
//     {
// 		c = tenths_to_hex(n % 16);
// 		str[len++] = tenths_to_hex(n % 16);
// 		n /= 16;
//     }
// 	if (n >= 0)
// 		str[len++] = tenths_to_hex(n);
// 	return (str);
// }

int main()
{
	long int	n = 0;
	float   resto;
	float	div;

	while (n < 100)
	{
		printf("N = %ld | hex = %lx | My = %s\n", n, n, ft_put_hex(n));

		delay(200);
		n++;
	}
	return (0);
}