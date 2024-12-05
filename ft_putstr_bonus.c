/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:33 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:11 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
