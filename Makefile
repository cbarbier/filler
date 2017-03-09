# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/03/09 17:14:09 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cbarbier.filler
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= srcs/main.c \
				  srcs/init_game.c \
				  srcs/map.c \
				  srcs/put_piece.c \
				  srcs/piece.c

all: $(NAME)

display:
	@echo "*******************"
	@echo "***project filler**"
	@echo "*******************\n"
$(NAME): display $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "IA BUILT\t\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
