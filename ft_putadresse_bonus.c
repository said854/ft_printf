/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:54 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:13:44 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_putpointer(ptr / 16);
	ft_putchar("0123456789abcdef"[ptr % 16]);
	return (len + 1);
}
