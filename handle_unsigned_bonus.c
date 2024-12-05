/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:20:59 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 20:14:51 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_padding(int padding, t_flags *flags)
{
	if (!flags->left_justify && padding > 0)
	{
		if (flags->zero_padding)
			return (ft_putnchar('0', padding));
		else
			return (ft_putnchar(' ', padding));
	}
	return (0);
}

static int	handle_precision(int num_len, t_flags *flags)
{
	if (flags->is_precision && flags->precision > num_len)
		return (ft_putnchar('0', flags->precision - num_len));
	return (0);
}

int	handle_unsigned(va_list args, t_flags *flags)
{
	unsigned int	num;
	int				len;
	int				num_len;
	int				padding;

	num = va_arg(args, unsigned int);
	len = 0;
	num_len = ft_unsint_len(num);
	padding = flags->width - num_len;
	len += handle_padding(padding, flags);
	len += handle_precision(num_len, flags);
	len += ft_putunsint(num);
	if (flags->left_justify && padding > 0)
		len += ft_putnchar(' ', padding);
	return (len);
}
