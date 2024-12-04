/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:25:54 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/04 14:32:48 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag_char(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static void	parse_flag_chars(const char **str, t_flags *flags)
{
	while (is_flag_char(**str))
	{
		if (**str == '-')
		{
			flags->left_justify = 1;
			flags->zero_padding = 0;
		}
		else if (**str == '0' && !flags->left_justify)
			flags->zero_padding = 1;
		else if (**str == '+')
			flags->plus_sign = 1;
		else if (**str == ' ')
			flags->space_sign = 1;
		else if (**str == '#')
			flags->hash = 1;
		(*str)++;
	}
}

static void	parse_width(const char **str, t_flags *flags)
{
	if (**str >= '1' && **str <= '9')
	{
		flags->width = ft_atoi(*str, flags);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

static void	parse_precision(const char **str, t_flags *flags)
{
	if (**str == '.')
	{
		flags->is_precision = 1;
		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			flags->precision = ft_atoi(*str, flags);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else
			flags->precision = 0;
	}
}

void	parse_flags(const char **str, t_flags *flags)
{
	*flags = (t_flags){0, 0, 0, 0, 0, 0, -1, 0, 0, 0};
	parse_flag_chars(str, flags);
	parse_width(str, flags);
	parse_precision(str, flags);
}
