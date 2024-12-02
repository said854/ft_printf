/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:33 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:11:51 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(const char *str)
{
	int len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return len;
}
