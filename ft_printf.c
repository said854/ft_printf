/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:37 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 12:47:07 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_format(const char **str, va_list args, int *printlen)
{
	t_flags	flags;

	parse_flags(str, &flags);
	if (flags.fail == 1)
		return (-1);
	if (**str != '\0')
		*printlen += handle_specifier_with_flags(**str, &flags, args);
	(*str)++;
	return (*printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printlen;

	printlen = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_process_format(&str, args, &printlen) == -1)
			{
				printlen = -1;
				break ;
			}
		}
		else
			printlen += ft_putchar(*str++);
	}
	va_end(args);
	return (printlen);
}
