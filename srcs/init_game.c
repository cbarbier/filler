/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:43:00 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/08 15:15:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	init_map(t_game *g)
{
	int		index;

	if (!(g->map = ft_memalloc(g->height * sizeof(char *))))
			return (0);
	index = 0;
	while (index < g->height)
		if (!(g->map[index++] = ft_memalloc(g->width * sizeof(char))))
			return (0);
	return (1);
}

static int	get_board_size(t_game *g)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (0);
	g->height = ft_atoi(line + 8);
	g->width = ft_atoi(ft_strchr(line + 8, ' ') + 1);
	return (1);
}

static int	get_player_id(t_game *g)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		return (0);
	g->player = *(line + 10) - '0';
	ft_strdel(&line);
	return (1);
}

int			init_game(t_game *g)
{
	ft_bzero(g, sizeof(t_game));
	g->fd = open("test.txt", O_WRONLY | O_APPEND);
	if (!get_player_id(g))
		return (0);
	if (!get_board_size(g))
		return (0);
	ft_fprintf(g->fd, "p%d h%d h%d\n", g->player, g->height, g->width);
	if (!init_map(g))
		return(0);
	return (1);
}
