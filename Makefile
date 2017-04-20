# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/04/18 14:35:13 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cbarbier.filler
LIB				= libft/libft.a
VISUAL			= visual/visual.out
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= srcs/main.c \
				  srcs/init_game.c \
				  srcs/map.c \
				  srcs/compute_piece.c \
				  srcs/set_info.c \
				  srcs/test_piece.c \
				  srcs/piece.c

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

display:
	@echo "*******************"
	@echo "***project filler**"
	@echo "*******************\n"

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): display $(LIB) $(OBJS) $(VISUAL)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(MLX)
	@echo "IA BUILT\t\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

$(VISUAL):
	@make -C visual

clean:
	@/bin/rm -rf $(OBJS)
	@make -C libft clean
	@make -C visual clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean
	@make -C visual fclean

re: fclean all

.PHONY: clean fclean all re
