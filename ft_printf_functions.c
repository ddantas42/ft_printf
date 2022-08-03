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

int	ft_putvoid(unsigned long int *p)
{
	int	n;

	n = 2;
	write(1, "0x", n);
	n += ft_put_hex(&p, 0);
	return (n);
}

int	ft_putnbr_pf(int n)
{
	char	*str;
	int		i;
	char	c;

	if (n)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (0);
		str[0] = '1';
		i = 0;
		while (str[i])
			write(1, &str[i++], 1);
		free(str);
		return (i);
	}
	if (!n)
		return (0);
	c = '0';
	write(1, &c, 1);
	return (1);
}

int	ft_put_perc(void)
{
	write(1, "%", 1);
	return (1);
}
