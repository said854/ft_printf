/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:07:27 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:15:25 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_sign(int num, t_flags *flags)
{
	if (num < 0)
		return (ft_putchar('-'));
	if (flags->plus_sign)
		return (ft_putchar('+'));
	if (flags->space_sign)
		return (ft_putchar(' '));
	return (0);
}
