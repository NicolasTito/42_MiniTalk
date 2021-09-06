NAME = client
NAME_BONUS = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

HEADER = ./includes/minitalk.h
HEADER_BONUS = ./includes/minitalk.h

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

INCLUDES = -I libft/includes -I ./includes

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC_NAME = client.c

SRC_BONUS = server.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
OBJB = $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRCB = $(addprefix $(SRC_PATH)/, $(SRC_BONUS))

all : $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "\x1b[36m[CLIENT COMPILED]\x1b[0m"

$(NAME_BONUS): $(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) $(INCLUDES) $(LIBFT) -o $(NAME_BONUS)
	@echo "\x1b[36m[SERVER COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p obj
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJB)
	@echo "\033[33mall $(NAME) and $(NAME_BONUS) .o files are removed\033[0m"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[31m$(NAME) and $(NAME_BONUS) is deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
