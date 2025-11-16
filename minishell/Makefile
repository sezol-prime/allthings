NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lreadline
INC			= -I include -I libft
SRC_DIR		= src
OBJ_DIR		= obj

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/signals/signals_heredoc.c \
	$(SRC_DIR)/signals/signals_interactive.c \
	$(SRC_DIR)/input.c \
	$(SRC_DIR)/lexer/lexer.c \
	$(SRC_DIR)/lexer/lexer_utils.c \
	$(SRC_DIR)/lexer/lexer_utils2.c \
	$(SRC_DIR)/parser/parser_build.c \
	$(SRC_DIR)/parser/parser_cmd.c \
	$(SRC_DIR)/parser/parser_collect.c \
	$(SRC_DIR)/parser/parser_main.c \
	$(SRC_DIR)/parser/parser_tokens.c \
	$(SRC_DIR)/env/env_array.c \
	$(SRC_DIR)/env/env_getset.c \
	$(SRC_DIR)/env/env_list.c \
	$(SRC_DIR)/env/env_node.c \
	$(SRC_DIR)/expander/expander.c \
	$(SRC_DIR)/expander/expander_utils1.c \
	$(SRC_DIR)/expander/expander_utils2.c \
	$(SRC_DIR)/exec/exec_child_core.c \
	$(SRC_DIR)/exec/exec_child_exec.c \
	$(SRC_DIR)/exec/exec_parent.c \
	$(SRC_DIR)/exec/exec_path.c \
	$(SRC_DIR)/exec/exec_pipeline.c \
	$(SRC_DIR)/exec/exec_wait.c \
	$(SRC_DIR)/redir.c \
	$(SRC_DIR)/heredoc.c \
	$(SRC_DIR)/util_mem.c \
	$(SRC_DIR)/util_vec.c \
	$(SRC_DIR)/status.c \
	$(SRC_DIR)/builtins/bi_echo.c \
	$(SRC_DIR)/builtins/bi_pwd.c \
	$(SRC_DIR)/builtins/bi_env.c \
	$(SRC_DIR)/builtins/bi_cd.c \
	$(SRC_DIR)/builtins/bi_export.c \
	$(SRC_DIR)/builtins/bi_unset.c \
	$(SRC_DIR)/builtins/dispatch.c \
	$(SRC_DIR)/builtins/bi_exit.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_DIRS = $(sort $(dir $(OBJ)))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIRS):
	mkdir -p $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
