/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:38:36 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 14:24:44 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_padding(int padding)
{
	if (padding > 0)
		return (ft_putnchar(' ', padding));
	return (0);
}

static int	handle_string_precision(char *str, t_flags *flags)
{
	int	str_len;

	if (flags->check_nul == 1)
		return (str_len = 0);
	str_len = ft_strlen(str);
	if (flags->is_precision && flags->precision >= 0)
	{
		if (flags->precision < str_len)
			str_len = flags->precision;
	}
	return (str_len);
}

int	handle_string(va_list args, t_flags *flags)
{
	char	*str;
	int		len;
	int		str_len;
	int		padding;

	str = va_arg(args, char *);
	if (!str && flags->is_precision && flags->precision <= 5 && !flags->width)
		return (len = 0);
	if (!str && flags->is_precision && flags->precision <= 5 && flags->width)
		flags->check_nul = 1;
	if (!str)
		str = "(null)";
	str_len = handle_string_precision(str, flags);
	padding = flags->width - str_len;
	if (flags->left_justify)
	{
		len = ft_putnstr(str, str_len);
		len += handle_padding(padding);
	}
	else
	{
		len = handle_padding(padding);
		len += ft_putnstr(str, str_len);
	}
	return (len);
}
