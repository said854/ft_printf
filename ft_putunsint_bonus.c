/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:38 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:16 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putunsint(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsint(n / 10);
	ft_putchar(n % 10 + '0');
	return (len + 1);
}
