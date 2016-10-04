# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/07 10:52:01 by gtandeo           #+#    #+#              #
#    Updated: 2016/09/27 22:56:16 by gtandeo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

LIBDIR = libft

CC = cc

SERVER = server

CLIENT = client

SRCS = srcs/

SRC_SERVER = server.c \
				login_data.c \
				connexion.c \
				exec_ls.c \
				exec_pwd.c \
				exec_get.c

SRC_CLIENT = client.c \
				wait_server.c

INCDIR = ./includes

CFLAGS = -Wall -Wextra -Werror

HEADERS = -Llibft -lft

LIBRARIES = -I $(INCDIR) -I $(LIBDIR)

all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	@make -C $(LIBDIR) fclean
	@make -C $(LIBDIR)

$(SERVER): $(LIB) $(addprefix $(SRCS),$(SRC_SERVER))
	@$(CC) $(addprefix $(SRCS),$(SRC_SERVER)) $(CFLAGS) $(HEADERS) $(LIBRARIES) -o $(SERVER)
	@echo "\033[33m"$(SERVER) Compiled ! "\033[32m"Success

$(CLIENT): $(LIB) $(addprefix $(SRCS),$(SRC_CLIENT))
	@$(CC) $(addprefix $(SRCS),$(SRC_CLIENT)) $(CFLAGS) $(HEADERS) $(LIBRARIES) -o $(CLIENT)
	@echo "\033[33m"$(CLIENT) Compiled ! "\033[32m"Success

clean:
	@make clean -C $(LIBDIR)
	@echo "\033[33m"libft objects Deleted ! "\033[32m"Success

fclean: clean
	@rm -f $(SERVER)
	@echo "\033[33m"$(SERVER) Deleted ! "\033[32m"Success
	@rm -f $(CLIENT)
	@echo "\033[33m"$(CLIENT) Deleted ! "\033[32m"Success
	@make fclean -C $(LIBDIR)
	@echo "\033[33m"libft.a Deleted ! "\033[32m"Success

re: fclean all

.PHONY: fclean re
