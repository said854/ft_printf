/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:38 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 13:00:28 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsint(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsint(n / 10);
	ft_putchar(n % 10 + '0');
	return (len + 1);
}
