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
// 	int		n;

// 	n = 0;
// 	while (len)
// 		write(1, &str[len--], 1);
// 	free(str);
// 	return (len);
// }

int	ft_put_hex(long int n)
{
	char	*str = malloc(16);
	int		len;

	len = 0;
	if (n < 0)
		return ("0");
	while (n > 15)
    {
		str[len++] = tenths_to_hex(n % 16);
		n /= 16;
    }
	if (n >= 0)	
		str[len++] = tenths_to_hex(n);
	write(1, str, len);
	return (len);
}

