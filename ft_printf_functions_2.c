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

int ft_put_hex(int n)
{
    char    *str;
    float   float_n;

    str = malloc((ft_inlen(n) - 1) * sizeof(char));
    while(n)
    {
        n /= 16;
        if (n < 16)

    }

    return (ft_strlen(n) - 1);
}

int ft_put_hex_caps(int n)
{

}