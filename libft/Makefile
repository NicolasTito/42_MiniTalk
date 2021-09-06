# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 14:57:28 by nide-mel          #+#    #+#              #
#    Updated: 2021/08/26 16:26:51 by nide-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

PATH_SRC = ./libc/

OBJ_PATH = ./obj

CFLAGS = -Wall -Wextra -Werror

INC = -I./includes

SRC = ft_memset.c	\
	ft_bzero.c	\
	ft_memcpy.c	\
	ft_memccpy.c	\
	ft_memmove.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_strlen.c	\
	ft_strlcpy.c	\
	ft_strlcat.c	\
	ft_strchr.c	\
	ft_strrchr.c	\
	ft_strnstr.c	\
	ft_strncmp.c	\
	ft_atoi.c	\
	ft_isalpha.c	\
	ft_isdigit.c	\
	ft_isalnum.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_toupper.c	\
	ft_tolower.c	\
	ft_calloc.c	\
	ft_strdup.c	\
	ft_substr.c	\
	ft_strjoin.c	\
	ft_strtrim.c	\
	ft_split.c	\
	ft_itoa.c	\
	ft_strmapi.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c	\
	ft_lstdelone.c	\
	ft_lstiter.c	\
	ft_lstlast.c	\
	ft_lstmap.c	\
	ft_lstnew.c	\
	ft_lstsize.c	\

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[36m[LIBFT COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
