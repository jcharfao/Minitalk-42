/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:34:57 by jcharfao          #+#    #+#             */
/*   Updated: 2024/11/06 05:35:46 by jcharfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int atoi(const char *str)
{
    int sign = 1;
    long result = 0;

    // Saltar los espacios en blanco
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    // Manejar el signo, si lo hay
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Convertir la cadena a número
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Devolver el resultado con el signo
    return (int)(sign * result);
}
