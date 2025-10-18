# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahari <rarahari@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:21:18 by rarahari          #+#    #+#              #
#    Updated: 2025/04/15 23:36:12 by rarahari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_printf.c ft_print_function.c ft_point.c ft_put_hexa.c
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a


all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
