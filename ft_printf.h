/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:20:53 by sjoukni           #+#    #+#             */
/*   Updated: 2024/12/02 17:49:16 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_printf_H
# define FT_printf_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>


typedef struct s_flags
{
	int left_justify;   // '-'
	int zero_padding;   // '0'
	int plus_sign;      // '+'
	int space_sign;     // ' '
	int hash;           // '#'
	int width;          // Minimum field width
	int precision;      // Precision value
	int is_precision;   // If a precision value is set
} t_flags;

int		ft_printf(const char *, ...);
void    parse_flags(const char **str, t_flags *flags, va_list args);
int     handle_specifier_with_flags(char c, t_flags *flags, va_list args);
int     handle_integer(va_list args, t_flags *flags);
int		ft_abs(int n);
int		print_sign(int num, t_flags *flags);
int		handle_unsigned(va_list args, t_flags *flags);
int 	handle_hex(va_list args, const char *base, t_flags *flags);
int		handle_string(va_list args, t_flags *flags);
int		handle_pointer(va_list args, t_flags *flags);
int     ft_putnchar(char c, int n);
int	    ft_putchar(char c);
int     ft_hex_len(unsigned int n);
int     ft_unsint_len(unsigned int n);
int     ft_pointer_len(unsigned long long ptr);
int     ft_nbr_len(int nbr);
int     ft_putnstr(const char *str, int n);
int	    ft_putnbr(int n);
int	    ft_putstr(const char *s);
int     ft_puthex(unsigned int n, const char *base);
int     ft_putpointer(unsigned long long ptr);
int     ft_putunsint(unsigned int nb);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
