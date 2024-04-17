SERVER = ./server

CLIENT = ./client

SRCS_DIR = ./srcs

INCLUDES = ./includes

SERVER_C = $(SRCS_DIR)/$(SERVER).c

CLIENT_C = $(SRCS_DIR)/$(CLIENT).c

BUILD_DIR = ./build

CLIENT_OBJ = $(CLIENT_C:%.c=$(BUILD_DIR)/%.o)

SERVER_OBJ = $(SERVER_C:%.c=$(BUILD_DIR)/%.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

CC = cc

all: $(SERVER) $(CLIENT)

$(SERVER):$(SERVER_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT):$(CLIENT_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

$(BUILD_DIR)/%.o : %.c $(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd $(LIBFT_DIR) && make && cd ..

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(LIBFT_DIR)/build

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(LIBFT)

re : fclean $(SERVER) $(CLIENT)

.PHONY : all clean fclean re

