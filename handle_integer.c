/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:30:52 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 14:33:06 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	c_padding(int num_len, t_flags *flags, int precision_p, int num)
{
	int	padding;
	int	padding_type;

	padding = flags->width - num_len - precision_p ;
	if (num_len < 0 || flags->plus_sign || flags->space_sign || num < 0)
		padding--;
	if (flags->zero_padding && !flags->left_justify)
		padding_type = '0';
	else
		padding_type = ' ';
	if (padding < 0)
		padding = 0;
	return (padding);
}

static int	handle_special_case(int num, int *len)
{
	if (num == -2147483648)
	{
		*len += ft_putchar('-');
		*len += ft_putstr("2147483648");
		return (*len);
	}
	return (0);
}

static int	h_left(int num, t_flags *flags, int precision_p, int space_padding)
{
	int	len;

	len = 0;
	len += print_sign(num, flags);
	len += ft_putnchar('0', precision_p);
	len += ft_putnbr(ft_abs(num));
	len += ft_putnchar(' ', space_padding);
	return (len);
}

static int	h_right(int num, t_flags *flags, int precision_p, int space_padding)
{
	int	len;
	int	padding_type;

	len = 0;
	if (flags->zero_padding && !flags->is_precision)
	{
		len += print_sign(num, flags);
		padding_type = '0';
		len += ft_putnchar(padding_type, space_padding);
		len += ft_putnchar('0', precision_p);
		len += ft_putnbr(ft_abs(num));
	}
	else
	{
		padding_type = ' ';
		len += ft_putnchar(padding_type, space_padding);
		len += print_sign(num, flags);
		len += ft_putnchar('0', precision_p);
		if (!(flags->is_precision && flags->precision == 0 && num == 0))
			len += ft_putnbr(ft_abs(num));
	}
	return (len);
}

int	handle_integer(va_list args, t_flags *flags)
{
	int	num;
	int	num_len;
	int	precision_padding;
	int	space_padding;
	int	len;

	num = va_arg(args, int);
	if (flags->is_precision && flags->precision == 0 && num == 0)
		num_len = 0;
	else
		num_len = ft_nbr_len(num);
	precision_padding = 0;
	space_padding = 0;
	len = 0;
	if (flags->is_precision && flags->precision > num_len)
		precision_padding = flags->precision - num_len;
	len = handle_special_case(num, &len);
	if (len > 0)
		return (len);
	space_padding = c_padding(num_len, flags, precision_padding, num);
	if (flags->left_justify)
		return (h_left(num, flags, precision_padding, space_padding));
	else
		return (h_right(num, flags, precision_padding, space_padding));
}
