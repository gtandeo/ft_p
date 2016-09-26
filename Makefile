# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/07 10:52:01 by gtandeo           #+#    #+#              #
#    Updated: 2016/09/01 15:40:32 by gtandeo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

LIBDIR = libft

SERVER = server

CLIENT = client

SRC_DIR = srcs/

SRC_SERVER = server.c

SRC_CLIENT = client.c

INCDIR = ./includes

CFLAGS = -Wall -Wextra -Werror -L libft -lft -I $(INCDIR)

all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	@make -C $(LIBDIR) fclean
	@make -C $(LIBDIR)

$(SERVER): $(LIB) $(addprefix $(SRC_DIR),$(SRC_SERVER))
	@cc -o $(SERVER) $(addprefix $(SRC_DIR),$(SRC_SERVER)) $(CFLAGS)
	@echo "\033[33m"$(SERVER) Compiled ! "\033[32m"Success

$(CLIENT): $(LIB) $(addprefix $(SRC_DIR),$(SRC_CLIENT))
	@cc -o $(CLIENT) $(addprefix $(SRC_DIR),$(SRC_CLIENT)) $(CFLAGS)
	@echo "\033[33m"$(CLIENT) Compiled ! "\033[32m"Success

clean:
	@make clean -C $(LIBDIR)

fclean: clean
	@rm -f $(SERVER)
	@echo "\033[33m"$(SERVER) Deleted ! "\033[32m"Success
	@rm -f $(CLIENT)
	@echo "\033[33m"$(CLIENT) Deleted ! "\033[32m"Success
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: fclean re
