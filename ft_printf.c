/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:37 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 14:10:22 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	int printlen = 0;
	t_flags flags;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			parse_flags(&str, &flags, args);
			if (*str != '\0')
				printlen += handle_specifier_with_flags(*str, &flags, args);
			str++;
		}
		else
			printlen += ft_putchar(*str++);
	}
	va_end(args);
	return printlen;
}
