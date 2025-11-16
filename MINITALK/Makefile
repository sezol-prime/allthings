# Program names
SERVER_NAME = server
CLIENT_NAME = client

# Compiler settings
CC      = cc
CFLAGS  = -Wall -Wextra -Werror 

# libft
LIBFT_DIR    = libft
LIBFT        = $(LIBFT_DIR)/libft.a

# Sources & Objects
SRCS_SERVER  = server.c
SRCS_CLIENT  = client.c
OBJS_SERVER  = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT  = $(SRCS_CLIENT:.c=.o)

# Default targe

all: $(SERVER_NAME) $(CLIENT_NAME)

# Build server (depends on libft)
$(SERVER_NAME): $(OBJS_SERVER) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER_NAME)

# Build client (depends on libft)
$(CLIENT_NAME): $(OBJS_CLIENT) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR)/inc -c $< -o $@

# ——— libft automation ———

# Only one rule for building libft.a
$(LIBFT):
	@echo ">>> building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Clean objects and submodule artifacts
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

# Full clean including executables, libft.a, stamp
fclean: clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
