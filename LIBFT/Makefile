# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 02:44:40 by sitao             #+#    #+#              #
#    Updated: 2024/12/24 02:44:43 by sitao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	定义变量
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

#	源文件列表
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

#	所有目标文件
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

#	默认目标：编译静态库
all: $(NAME)

#	规则：编译强制部分的库文件
$(NAME): $(OBJ)
	@echo "Creating libft.a..."
	$(AR) $(NAME) $(OBJ)
	@echo "libft.a created successfully!"

#	规则：编译 Bonus 部分的库文件
bonus: $(OBJ) $(BONUS_OBJ)
	@echo "Creating libft.a with Bonus files..."
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "libft.a with bonus created successfully!"

#	规则：将 .c 文件编译为 .o 文件
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

#	清理中间文件
clean:
	@echo "Removing object files..."
	$(RM) $(OBJ) $(BONUS_OBJ)

#	清理所有文件，包括库文件
fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)

#	重新编译
re: fclean all

#	伪目标，避免与文件名冲突
.PHONY: all clean fclean re bonus
