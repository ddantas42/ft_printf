/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:45:43 by ddantas-          #+#    #+#             */
/*   Updated: 2022/08/08 10:23:51 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
// # include "./libft/libft.h"

// ft_prinft.c
int		ft_printf(const char *str, ...);

// ft_printf_utils.c
int		check_perc(const char *str, int n);
int		ft_funcion_selector(char c, va_list ap);

// ft_printf_functions.c
int		ft_putvoid(unsigned long int p, int caps);
int		put_nbr_if(int n, int sinal);
int		int_len(int n);
void	print_str(int i, char *str, int n, int len);
int		ft_putnbr_pf(int n);

// ft_printf_function_2.c
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
char	tenths_to_hex(unsigned int n, int caps);
int		ft_put_hex(unsigned int n, int caps);
int		ft_put_perc(void);

// ft_printf_functions_3.c


#endif