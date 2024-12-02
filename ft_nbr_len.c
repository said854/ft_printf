/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:24:28 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:10:17 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_nbr_len(int nbr)
{
    int len;

    len = 1;  // At least one digit
    if (nbr < 0)
    {
        nbr = -nbr;  // Make the number positive if it's negative
    }
    while (nbr >= 10)
    {
        nbr /= 10;
        len++;
    }
    return len;
}
