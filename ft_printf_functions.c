/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:19:36 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/24 13:19:38 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *s)
{
	int	n;

	n = 0;
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			n++;
		}
		return (n);
	}
	write(1, "(null)", 6);
	return (6);
}

int	ft_putvoid(unsigned long int p, int caps)
{
	char	*str;
	int		len;
	int		i;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	str = malloc(25);
	if (!str)
		return (0);
	len = 0;
	while (p > 15)
	{
		str[len++] = tenths_to_hex(p % 16, caps);
		p /= 16;
	}
	str[len] = tenths_to_hex(p, caps);
	i = len + 1;
	while (--i)
		write(1, &str[i], 1);
	write(1, &str[i], 1);
	free(str);
	return (len + 1 + 2);
}

int	ft_putnbr_pf(int n)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	if (put_nbr_if(n, -1) == 11)
		return (11);
	if (put_nbr_if(n, 1) == 1)
	{
		n *= -1;
		len++;
	}
	i = 0;
	str = malloc(11);
	if (!str)
		return (0);
	while (n >= 10)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = n + 48;
	while (i)
	{
		write(1, &str[i--], 1);
		len++;
	}
	write(1, &str[i--], 1);
	free(str);
	return (len + 1);
}

int	put_nbr_if(int n, int sinal)
{
	if (n == -2147483648 && sinal == -1)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0 && sinal != -1)
	{
		write(1, "-", 1);
		n++;
		return (1);
	}
	return (0);

}
