# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 20:41:24 by sitao             #+#    #+#              #
#    Updated: 2025/05/30 20:41:38 by sitao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

SRC_DIR     = srcs
OBJ_DIR     = obj
INC_DIR     = inc
LIBFT_DIR   = libft

LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_STAMP = $(LIBFT_DIR)/.done

COMMANDS_SRC  = \
    $(SRC_DIR)/commands/push.c \
    $(SRC_DIR)/commands/rev_rotate.c \
    $(SRC_DIR)/commands/rotate.c \
    $(SRC_DIR)/commands/swap.c

PUSH_SWAP_SRC = \
    $(SRC_DIR)/push_swap/error_free.c \
    $(SRC_DIR)/push_swap/get_cheapest.c \
    $(SRC_DIR)/push_swap/init_nodes_a.c \
    $(SRC_DIR)/push_swap/init_nodes_b.c \
    $(SRC_DIR)/push_swap/push_swap.c \
    $(SRC_DIR)/push_swap/sort_stack.c \
    $(SRC_DIR)/push_swap/sort_stack_utils.c \
    $(SRC_DIR)/push_swap/stack_init.c \
    $(SRC_DIR)/push_swap/stack_utils.c \
    $(SRC_DIR)/push_swap/sort_three.c

SRCS        = $(COMMANDS_SRC) $(PUSH_SWAP_SRC)
OBJ         = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/inc
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_STAMP)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_STAMP): $(LIBFT)
	@touch $@

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT) $(LIBFT_STAMP)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
