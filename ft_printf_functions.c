/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:19:36 by ddantas-          #+#    #+#             */
/*   Updated: 2022/08/08 12:30:55 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_function(unsigned long int p, int caps)
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
		str[len++] = x_util(p % 16, caps);
		p /= 16;
	}
	str[len] = x_util(p, caps);
	i = len + 1;
	while (--i >= 0)
		write(1, &str[i], 1);
	free(str);
	return (len + 1 + 2);
}

int	nbr_if(int n, int sinal)
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

int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	print_str(int i, char *str, int n, int len)
{
	str[len] = '\0';
	while (n >= 10)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = n + 48;
	while (i >= 0)
		write(1, &str[i--], 1);
	free(str);
}

int	nbr_function(int n)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	if (nbr_if(n, -1) == 11)
		return (11);
	if (nbr_if(n, 1) == 1)
	{
		n *= -1;
		len++;
	}
	len += int_len(n);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	print_str(i, str, n, len);
	return (len);
}
