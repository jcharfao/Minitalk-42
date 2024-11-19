# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 01:25:47 by jcharfao          #+#    #+#              #
#    Updated: 2024/11/08 01:39:35 by jcharfao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BIN

SERVER_NAME = server
CLIENT_NAME = client

# CF

CF = -Wall -Werror -Wextra
CF += -I$(INC_DIR)

# DIR

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIBFT_DIR = libft/

# FILES

SRC_FILES_SERVER = server.c
SRC_FILES_CLIENT = client.c

OBJ_FILES_SERVER = $(SRC_FILES_SERVER:.c=.o)
OBJ_FILES_CLIENT = $(SRC_FILES_CLIENT:.c=.o)

OBJ_SERVER = $(addprefix $(OBJ_DIR), $(OBJ_FILES_SERVER))
OBJ_CLIENT = $(addprefix $(OBJ_DIR), $(OBJ_FILES_CLIENT))

# LIB

LIBFT_BIN = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_BIN))
LINKER = $(LIBFT)

# RULES

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CF) $(OBJ_SERVER) -o $(SERVER_NAME) $(LINKER)

$(CLIENT_NAME): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CF) $(OBJ_CLIENT) -o $(CLIENT_NAME) $(LINKER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CF) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re