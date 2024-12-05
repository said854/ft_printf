/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:48:49 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:36 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_pointer_padding(int ptr_len, t_flags *flags)
{
	int	padding;

	padding = flags->width - ptr_len;
	if (!flags->left_justify && padding > 0)
	{
		if (flags->zero_padding)
			return (ft_putnchar('0', padding));
		else
			return (ft_putnchar(' ', padding));
	}
	return (0);
}

static int	handle_pointer_left_padding(int ptr_len, t_flags *flags)
{
	int	padding;

	padding = flags->width - ptr_len - 2;
	if (flags->left_justify && padding > 0)
		return (ft_putnchar(' ', padding));
	return (0);
}

int	handle_pointer(va_list args, t_flags *flags)
{
	unsigned long long	ptr;
	int					len;
	int					ptr_len;

	ptr = va_arg(args, unsigned long long);
	len = 0;
	if (ptr == 0)
		return (len += ft_putstr("(nil)"));
	ptr_len = ft_pointer_len(ptr);
	len += handle_pointer_padding(ptr_len, flags);
	len += ft_putstr("0x");
	len += ft_putpointer(ptr);
	len += handle_pointer_left_padding(ptr_len, flags);
	return (len);
}
