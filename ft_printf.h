/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:45:43 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/24 10:45:45 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// ft_prinft.c
int		ft_printf(const char *str, ...);

// ft_printf_utils.c
int		check_perc(const char *str, int n);
int		ft_funcion_selector(char c, va_list ap);

// ft_printf_functions.c
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
int		ft_putnbr_pf(int n);
int		ft_put_perc(void);
int		ft_putvoid(unsigned long int p, int caps);

// ft_printf_functions2.c
char	tenths_to_hex(unsigned int n, int caps);
int		ft_put_hex(unsigned int n, int caps);

#endif