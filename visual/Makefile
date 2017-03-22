# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/03/22 19:57:58 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= visual.out
LIB				= libft/libft.a
LIBMLX			= minilibx_macos/libmlx.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX				= -Lminilibx_macos -lmlx -framework OpenGL -framework Appkit
SRCS			= srcs/visual.c \
				  srcs/map.c \
				  srcs/mlx.c \

all: $(NAME)

$(NAME): $(LIBMLX) $(LIB) $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Llibft -lft $(MLX)
	@echo "SHOWER  BUILT\t\t\033[0;32m✓\033[0m"

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

.PHONY: clean fclean all re
