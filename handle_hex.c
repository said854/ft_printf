/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:31:38 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 13:06:42 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_padding(int padding, int zero_padding)
{
	if (padding > 0)
	{
		if (zero_padding)
			return (ft_putnchar('0', padding));
		else
			return (ft_putnchar(' ', padding));
	}
	return (0);
}

static int	handle_prefix(int num, const char *base, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->hash && num != 0)
	{
		if (base[10] == 'a')
			len += ft_putstr("0x");
		else
			len += ft_putstr("0X");
	}
	return (len);
}

static int	h_padding(unsigned int num, int num_len, int prefix, t_flags *flags)
{
	int	padding;

	padding = flags->width - num_len - prefix;
	if (flags->is_precision && flags->precision > num_len)
		padding = flags->width - flags->precision - prefix;
	if (flags->is_precision && flags->precision == 0 && num == 0)
	{
		if (flags->width > 0)
			return (handle_padding(flags->width, 0));
	}
	return (padding);
}

int	handle_hex(va_list args, const char *base, t_flags *flags)
{
	unsigned int	num;
	int				len;
	int				num_len;
	int				prefix_len;
	int				padding;

	num = va_arg(args, unsigned int);
	len = 0;
	num_len = ft_hex_len(num);
	prefix_len = 0;
	if (flags->hash && num != 0)
		prefix_len = 2;
	padding = h_padding(num, num_len, prefix_len, flags);
	if (!flags->left_justify && padding > 0)
		len += handle_padding(padding, flags->zero_padding);
	len += handle_prefix(num, base, flags);
	if (flags->is_precision && flags->precision > num_len)
		len += ft_putnchar('0', flags->precision - num_len);
	len += ft_puthex(num, base);
	if (flags->left_justify && padding > 0)
		len += handle_padding(padding, 0);
	return (len);
}
