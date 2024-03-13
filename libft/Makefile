NAME=libft.a

LIBRARY_DIR = ./

LIBFT_A = $(LIBRARY_DIR)/$(NAME)

CC=cc

INCLUDE_FOLDER = ./includes

CFLAGS=-Wall -Wextra -Werror -I $(INCLUDE_FOLDER)

SRC_FOLDER = ./srcs

BUILD_DIR = ./build

RAW_SRCS = $(shell find $(SRC_FOLDER))

SRCS = $(filter %.c, $(RAW_SRCS))

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(LIBFT_A)

$(LIBFT_A): $(OBJS)
	ar rc $(LIBFT_A) $(OBJS)

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/$(SRC_FOLDER)

fclean: clean
	rm -f $(LIBFT_A)

re : fclean $(LIBFT_A)

.PHONY:  all clean fclean re
