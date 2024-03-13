SERVER = ./server

CLIENT = ./client

SRCS_DIR = ./srcs

SERVER_C = $(SRCS_DIR)/$(SERVER).c

CLIENT_C = $(SRCS_DIR)/$(CLIENT).c

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = ./includes

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

CC = cc

all: $(SERVER) $(CLIENT)

$(SERVER):$(SERVER_C) $(LIBFT)
	$(CC) $(FLAGS) $(SERVER_C) $(LIBFT) -o $(SERVER)

$(CLIENT):$(CLIENT_C) $(LIBFT)
	$(CC) $(FLAGS) $(CLIENT_C) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	cd $(LIBFT_DIR) && make && cd ..

clean:
	cd $(LIBFT_DIR) && make fclean && cd ..

fclean: clean
	rm $(SERVER) $(CLIENT)

re : fclean $(SERVER) $(CLIENT)

.PHONY : all clean fclean re

