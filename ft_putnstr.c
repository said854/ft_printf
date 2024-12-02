/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:44 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:11:47 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnstr(const char *str, int n)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (str[len] && len < n)
    {
        write(1, &str[len], 1);
        len++;
    }
    return len;
}
