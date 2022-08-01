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

char	*min_int(char *c)
{
	c[0] = '-';
	c[1] = '2';
	c[2] = '1';
	c[3] = '4';
	c[4] = '7';
	c[5] = '4';
	c[6] = '8';
	c[7] = '3';
	c[8] = '6';
	c[9] = '4';
	c[10] = '8';
	c[11] = 0;
	return (c);
}

char	*while_len(int len, int n2, char *c, int n)
{
	while (len--)
	{
		if (n2 < 0 && len == 1)
		{
			c[len--] = n + '0';
			c[len] = '-';
		}
		else
			c[len] = (n % 10) + 48;
		n /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		len;
	int		n2;

	n2 = n;
	len = ft_intlen(n);
	c = malloc(len + 1);
	if (!c)
		return (0);
	if (n == -2147483648)
		return (min_int(c));
	c[len] = 0;
	if (n < 0)
		n *= -1;
	c = while_len(len, n2, c, n);
	return (c);
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

char	*tenths_to_hex(int n)
{
	if (n < 10)
		return (ft_itoa(n));
	if (n >= 10)
		return (letters_hex(n));
	return (0);
}

void	*ft_put_hex(long int n)
{
	char	*c = malloc(2);
    float   resto;
	int		div;

    while(n > 15)
    {
		div = n / 16;
		resto = n % 16;
		write(1, tenths_to_hex(div), 1);
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
	long int	n = 15;
	float   resto;
	float	div;
	

	// while (n <= 100)
	// {
	// 	printf("Printf ! Hex = %x | n = %d\n", n, n);
	// 	ft_printf("FT ! Hex = %s | n = %d\n", ft_put_hex(n), n);
	// 	n++;
	// }

	printf("N = %ld | hex = %lx | my = ", n, n);
	ft_put_hex(n);
	printf(" |\n");


	return (0);
}