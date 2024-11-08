# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 01:42:54 by jcharfao          #+#    #+#              #
#    Updated: 2024/11/06 01:24:12 by jcharfao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BIN
NAME=server

#CF
// CF = -O0
CF += -Wall -Werror -Wextra
CF += -I$(INC_DIR)

#SOURCES
SRC_DIR=Src/
SRC_FILES= 		\
SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

#OBJ
OBJ_DIR=Obj/
OBJ_FILES=$(SRC_FILES:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#INCLUDES
INC_DIR=Inc/
INC_FILES= server.h\
INC=$(addprefix $(INC_DIR), $(INC_FILES))

#LIBFT
LIBFT_DIR=Libft/
LIBFT_BIN= libft.a
LIBFT=$(addprefix $(LIBFT_DIR), $(LIBFT_BIN))

#LINKER
LINKER= $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		gcc $(CF) $(OBJ) -o $(NAME) $(LINKER)

$(LIBFT):
		make -sC Libft

$(OBJ_DIR)%.o $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		gcc $(CF) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re