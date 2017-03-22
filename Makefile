# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/03/22 08:44:34 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cbarbier.filler
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -Lminilibx_macos -lmlx -framework OpenGL -framework Appkit
SRCS			= srcs/main.c \
				  srcs/init_game.c \
				  srcs/map.c \
				  srcs/compute_piece.c \
				  srcs/set_info.c \
				  srcs/test_piece.c \
				  srcs/piece.c \
				  srcs/mlx.c \
				  srcs/tools.c

all: $(NAME)

display:
	@echo "*******************"
	@echo "***project filler**"
	@echo "*******************\n"
$(NAME): display $(LIBMLX) $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "IA BUILT\t\t\033[0;32m✓\033[0m"

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX COMPILED\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBMLX)
	@make -C libft fclean

re: fclean all

test:
	rm test.txt && touch test.txt && ./filler_vm -p2 ./cbarbier.filler -p1 players/carli.filler -f maps/map00

.PHONY: clean fclean all re
