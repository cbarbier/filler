# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/03/27 10:34:32 by cbarbier         ###   ########.fr        #
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
				  srcs/mlx.c 
OBJS			= $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBMLX) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(MLX)
	@echo "SHOWER  BUILT\t\t\033[0;32m✓\033[0m"

$(LIBMLX):
	@make -C minilibx_macos
	@echo "MINILIBX COMPILED\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBMLX)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
