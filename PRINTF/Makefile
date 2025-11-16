# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 23:03:48 by sitao             #+#    #+#              #
#    Updated: 2025/02/25 23:03:52 by sitao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

TEST = test.c
TEST_EXE = test_ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

SRCS = ft_printf.c \
       ft_putchar_utils.c \
       ft_putstr_utils.c \
       ft_puthex_utils.c \
       ft_putnbr_utils.c \
       ft_putptr_utils.c \
       ft_putnbr_unsigned.c 

OBJS = $(SRCS:%.c=%.o)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

test:$(NAME) $(TEST)
	$(CC) $(CFLAGS) $(TEST) $(NAME) -o $(TEST_EXE)
	./$(TEST_EXE)
clean:
	$(RM) $(OBJS) $(TEST_EXE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re norm
