NAME		= libft.a

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
AR			= ar rcs
RM			= rm -rf

SRC = \
	src/ft_is/ft_isalnum.c \
	src/ft_is/ft_isalpha.c \
	src/ft_is/ft_isascii.c \
	src/ft_is/ft_isdigit.c \
	src/ft_is/ft_isprint.c \
	src/ft_mem/ft_bzero.c \
	src/ft_mem/ft_calloc.c \
	src/ft_mem/ft_memchr.c \
	src/ft_mem/ft_memcmp.c \
	src/ft_mem/ft_memcpy.c \
	src/ft_mem/ft_memmove.c \
	src/ft_mem/ft_memset.c \
	src/ft_put/ft_putchar_fd.c \
	src/ft_put/ft_putendl_fd.c \
	src/ft_put/ft_putnbr_fd.c \
	src/ft_put/ft_putstr_fd.c \
	src/ft_to/ft_atoi.c \
	src/ft_to/ft_itoa.c \
	src/ft_to/ft_tolower.c \
	src/ft_to/ft_toupper.c \
	src/ft_str/ft_split.c \
	src/ft_str/ft_strchr.c \
	src/ft_str/ft_strdup.c \
	src/ft_str/ft_striteri.c \
	src/ft_str/ft_strjoin.c \
	src/ft_str/ft_strlcat.c \
	src/ft_str/ft_strlcpy.c \
	src/ft_str/ft_strlen.c \
	src/ft_str/ft_strmapi.c \
	src/ft_str/ft_strncmp.c \
	src/ft_str/ft_strnstr.c \
	src/ft_str/ft_strrchr.c \
	src/ft_str/ft_strtrim.c \
	src/ft_str/ft_substr.c \
	src/ft_lst/ft_lstadd_back.c \
	src/ft_lst/ft_lstadd_front.c \
	src/ft_lst/ft_lstclear.c \
	src/ft_lst/ft_lstdelone.c \
	src/ft_lst/ft_lstiter.c \
	src/ft_lst/ft_lstlast.c \
	src/ft_lst/ft_lstmap.c \
	src/ft_lst/ft_lstnew.c \
	src/ft_lst/ft_lstsize.c \
	src/ft_printf/ft_printf.c \
	src/ft_printf/ft_putchar_utils.c \
	src/ft_printf/ft_putstr_utils.c \
	src/ft_printf/ft_putnbr_utils.c \
	src/ft_printf/ft_putnbr_unsigned.c \
	src/ft_printf/ft_puthex_utils.c \
	src/ft_printf/ft_putptr_utils.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c

OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(OBJ_DIR)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
