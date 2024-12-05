/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:33:04 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:02 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (n);
}
