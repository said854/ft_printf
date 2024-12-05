/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:15 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:13:54 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthex(unsigned int n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, base);
	ft_putchar(base[n % 16]);
	return (len + 1);
}
