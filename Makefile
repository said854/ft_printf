# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 15:37:14 by sjoukni           #+#    #+#              #
#    Updated: 2024/12/04 18:39:50 by sjoukni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c ft_atoi.c ft_nbr_len.c ft_putchar.c ft_putstr.c \
       ft_putnbr.c ft_printf.c ft_puthex.c ft_putunsint.c ft_putadresse.c \
       ft_hexlen.c ft_unsignedlen.c ft_addresslen.c ft_putnstr.c parse_flags.c \
       handle_specifier_with_flags.c handle_integer.c ft_putnchar.c ft_abs.c \
       print_sign.c handle_hex.c handle_unsigned.c handle_string.c handle_pointer.c
	   
SRCS_BONUS = ft_strlen_bonus.c ft_atoi_bonus.c ft_nbr_len_bonus.c ft_putchar_bonus.c ft_putstr_bonus.c \
           ft_putnbr_bonus.c ft_printf_bonus.c ft_puthex_bonus.c ft_putunsint_bonus.c ft_putadresse_bonus.c \
           ft_hexlen_bonus.c ft_unsignedlen_bonus.c ft_addresslen_bonus.c ft_putnstr_bonus.c parse_flags_bonus.c \
           handle_specifier_with_flags_bonus.c handle_integer_bonus.c ft_putnchar_bonus.c ft_abs_bonus.c \
           print_sign_bonus.c handle_hex_bonus.c handle_unsigned_bonus.c handle_string_bonus.c handle_pointer_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

bonus : $(NAME) $(OBJECTS_BONUS)
	$(AR) $(NAME) $(OBJECTS_BONUS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

.SECONDARY : $(OBJECTS) $(OBJECTS_BONUS)
