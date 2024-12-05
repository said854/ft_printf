/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:44 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:06 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnstr(const char *str, int n)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len] && len < n)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
