/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:21 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 15:09:24 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		// Special case for the smallest negative int
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		// If negative, print the minus sign
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		// Recursively print the number
		count += ft_putnbr(n / 10);
	}
	// Print the last digit
	count += ft_putchar((n % 10) + '0');

	return (count);
}

