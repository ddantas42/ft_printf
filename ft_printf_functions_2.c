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

// int	string_printer(char *str, int len)
// {
// 	while (--len)
// 	{
// 		write(1, &str[len], 1);
// 		len;
// 	}
// 	write(1, &str[len], 1);
// 	free(str);
// 	return (len);
// }

char	tenths_to_hex(unsigned int n)
{
	if (n < 10)
		return (n + 48);
	if (n >= 10)
		return (n + 87);
	return (0);
}

int	ft_put_hex(unsigned int n)
{
	char	*str = malloc(16);
	int		len;
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	len = 0;
	while (n > 15)
    {
		str[len++] = tenths_to_hex(n % 16);
		n /= 16;
		len++;
    }
	str[len++] = tenths_to_hex(n);
	i = len;
	while (str[i])
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, &str[i], 1);
	free(str);
	return (len);
}
