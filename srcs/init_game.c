/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:43:00 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:14 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	init_infos(t_game *g, t_info *info)
{
	info->minx = g->width;
	info->maxx = 0;
	info->miny = g->height;
	info->maxy = 0;
	return (1);
}

static int	init_map(t_game *g)
{
	if (!(g->map = (char **)ft_memalloc(g->height * sizeof(char *))))
		return (0);
	if (!(g->testmap = (char **)ft_memalloc(g->height * sizeof(char *))))
		return (0);
	if (!get_map(g))
		return (0);
	init_infos(g, &(g->myinfo));
	init_infos(g, &(g->ainfo));
	set_info(g);
	g->mystart.x = g->myinfo.minx;
	g->mystart.y = g->myinfo.maxy;
	g->aistart.x = g->ainfo.minx;
	g->aistart.y = g->ainfo.miny;
	return (1);
}

static int	get_board_size(t_game *g)
{
	char *line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strlen(line) < 9 || !ft_strchr(line + 8, ' '))
		return (0);
	g->height = ft_atoi(line + 8);
	g->width = ft_atoi(ft_strchr(line + 8, ' ') + 1);
	return (1);
}

static int	get_player_id(t_game *g)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strlen(line) < 10)
		return (0);
	g->player = *(line + 10) - '0';
	ft_strdel(&line);
	g->me = (g->player == 1 ? 'O' : 'X');
	g->adv = (g->me == 'O' ? 'X' : 'O');
	return (1);
}

int			init_game(t_game *g)
{
	ft_bzero(g, sizeof(t_game));
	if (!get_player_id(g))
		return (0);
	if (!get_board_size(g))
		return (0);
	if (!init_map(g))
		return (0);
	return (1);
}
