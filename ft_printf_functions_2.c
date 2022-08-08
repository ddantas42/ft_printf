/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:53:04 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/25 16:53:23 by ddantas-         ###   ########.fr       */
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

char	tenths_to_hex(unsigned int n, int caps)
{
	if (n < 10)
		return (n + 48);
	if (n >= 10)
	{
		if (caps)
			return (n + 55);
		else
			return (n + 87);
	}
	return (0);
}

int	ft_put_hex(unsigned int n, int caps)
{
	char	*str;
	int		len;
	int		i;

	str = malloc(25);
	if (!str)
		return (0);
	len = 0;
	while (n > 15)
	{
		str[len++] = tenths_to_hex(n % 16, caps);
		n /= 16;
	}
	str[len] = tenths_to_hex(n, caps);
	i = len;
	while (i)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, &str[i], 1);
	free(str);
	return (len + 1);
}

int	ft_put_perc(void)
{
	write(1, "%", 1);
	return (1);
}
