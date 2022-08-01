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

int	*ft_put_hex(long int n)
{
	char	*str = malloc(16);
	int		len;
	char	c;
    float   resto;
	int		div;

	len = 0;
	if (n)
		return ("0");
	while (n > 15)
    {
		div = n / 16;
		resto = n % 16;
		str[len++] = tenths_to_hex(resto);
		n /= 16;
    }
	if (n > 0)
		str[len++] = tenths_to_hex(n);
	return (string_inverter(str));
}

