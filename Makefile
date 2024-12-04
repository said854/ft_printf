# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 15:37:14 by sjoukni           #+#    #+#              #
#    Updated: 2024/12/04 15:09:16 by sjoukni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_strlen.c  ft_atoi.c ft_nbr_len.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_puthex.c ft_putunsint.c ft_putadresse.c   ft_hexlen.c ft_unsignedlen.c ft_addresslen.c   ft_putnstr.c  parse_flags.c handle_specifier_with_flags.c handle_integer.c ft_putnchar.c ft_putchar.c ft_abs.c print_sign.c handle_hex.c handle_unsigned.c handle_string.c handle_pointer.c

OBJECTS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ft_printf.h
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re

.SECONDARY : $(OBJECTS)