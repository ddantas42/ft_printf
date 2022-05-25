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
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
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
	return (0);
}

int	ft_putnbr_pf(int n)
{
	char	*str;
	int		i;
	char	c;

	if (n)
	{
		str = ft_itoa(n);
		i = 0;
		while (str[i])
			write(1, &str[i++], 1);
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
	char	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}
