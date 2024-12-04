/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier_with_flags.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:27:54 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 14:23:41 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args, t_flags *flags)
{
	char	c;
	int		len;

	c = (char)va_arg(args, int);
	len = 0;
	if (!flags->left_justify && flags->width > 1)
		len += ft_putnchar(' ', flags->width - 1);
	len += ft_putchar(c);
	if (flags->left_justify && flags->width > 1)
		len += ft_putnchar(' ', flags->width - 1);
	return (len);
}

static int	handle_percent_padding(int width)
{
	if (width > 1)
		return (width - 1);
	return (0);
}

int	handle_percent(t_flags *flags)
{
	int	len;
	int	padding;

	len = 0;
	padding = handle_percent_padding(flags->width);
	if (flags->left_justify)
	{
		len += ft_putchar('%');
		if (padding > 0)
			len += ft_putnchar(' ', padding);
	}
	else
	{
		if (padding > 0)
			len += ft_putnchar(' ', padding);
		len += ft_putchar('%');
	}
	return (len);
}

int	handle_specifier_with_flags(char c, t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += handle_integer(args, flags);
	else if (c == 'u')
		len += handle_unsigned(args, flags);
	else if (c == 'x')
		len += handle_hex(args, "0123456789abcdef", flags);
	else if (c == 'X')
		len += handle_hex(args, "0123456789ABCDEF", flags);
	else if (c == 's')
		len += handle_string(args, flags);
	else if (c == 'c')
		len += handle_char(args, flags);
	else if (c == 'p')
		len += handle_pointer(args, flags);
	else if (c == '%')
		len += handle_percent(flags);
	return (len);
}
