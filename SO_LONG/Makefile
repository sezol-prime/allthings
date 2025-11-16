# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sitao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:38:04 by sitao             #+#    #+#              #
#    Updated: 2025/06/03 16:38:09 by sitao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME        = so_long

# Directories
SRC_DIR     = Mandatory/src
OBJ_DIR     = obj
INC_DIR     = inc
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# Source files
SRCS_FILENAMES = \
	so_long.c \
	so_long_utils.c \
	so_long_utils_free.c \
	path_checker.c \
	movement.c \
	move_hook.c \
	map_render.c \
	map_printer.c \
	map_init.c \
	map_array.c \
	map_checker.c \
	map_checker_wall.c \
	map_checker_params.c \
	exit_win.c \
	free_all.c 

SRC_FILES   = $(addprefix $(SRC_DIR)/, $(SRCS_FILENAMES))
OBJ_FILES   = $(addprefix $(OBJ_DIR)/, $(SRCS_FILENAMES:.c=.o))

# Libraries and stamps
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx_Linux.a
LIBFT_STAMP = $(LIBFT_DIR)/.done
MLX_STAMP   = $(MLX_DIR)/.done
LIBS        = $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd

# Include paths
INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(MLX_DIR)

# Compiler flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Build the executable; relink only if .o or stamps have changed
$(NAME): $(OBJ_FILES) $(LIBFT_STAMP) $(MLX_STAMP)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(INCLUDES) $(LIBS) -o $(NAME)

# Compile each .c to .o; only when that .c changes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft only when libft.a is missing or cleaned
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Touch stamp only after libft.a exists
$(LIBFT_STAMP): $(LIBFT)
	@touch $@

# Build mlx only when libmlx_Linux.a is missing or cleaned
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Touch stamp only after libmlx_Linux.a exists
$(MLX_STAMP): $(MLX)
	@touch $@

# Clean obj directories and submodule artifacts
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

# Full clean including executable and stamps
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_STAMP) $(MLX_STAMP)
	@$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
