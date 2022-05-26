/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:37:22 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/24 12:37:23 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_perc(const char *str, int n)
{
	if (str[n + 1] == 'c' || str[n + 1] == 's' || str[n + 1] == 'p'
		|| str[n + 1] == 'd' || str[n + 1] == 'i' || str[n + 1] == 'u'
		|| str[n + 1] == 'x' || str[n + 1] == 'X' || str[n + 1] == '%')
		return (1);
	return (0);
}

int	ft_funcion_selector(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(ap, int))); // done
	if (c == 's')
		return (ft_putstr_pf(va_arg(ap, char *)));  // done
	if (c == 'p')
		return (ft_putvoid(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr_pf(va_arg(ap, int)));
	if (c == 'x')
		return (ft_put_hex(va_arg(ap, int)));
	if (c == 'X')
		return (ft_put_hex_caps(va_arg(ap, int)));
	if (c == '%')
		return (ft_put_perc);
	return (0);
}
