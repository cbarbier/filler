/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 17:16:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			parse_map(t_game *g, int (*f)(t_game *, int, int))
{
	int		j;
	int		i;

	j = 0;
	while (j < g->height)
	{
		i = 0;
		while (i < g->width)
		{
			if (!f(g, i, j))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int			is_target_reached(t_game *g)
{
	t_info *t;
	t_info *m;
	int		count;

	t = &(g->advpos);
	m = &(g->myinfo);
	count = 0;
	if (m->minx > t->minx)
		count++;
	if (m->maxx < t->maxx)
		count++;
	if (m->miny > t->miny)
		count++;
	if (m->maxy < t->maxy)
		count++;
	return (count >= 3 ? 1 : 0);
}

static int	find_adv_last_piece(t_env *e, char *lastr, char *newr, int raw)
{
	int		index;
	int		count;
	t_game	*g;

	g = e->game;
	index = 0;
	count = 0;
	while (index < g->width)
	{
		set_deltas(&(g->advpos), index, raw);
		if ((!g->loopcount || lastr[index] != g->adv) && newr[index] == g->adv)
		{
			if (!count)
				g->advpos.x = index;
			if (!count)
				g->advpos.y = raw;
			draw_case(e, index, raw, g->adv + 32);
			count++;
		}
		index++;
	}
	return (count ? 1 : 0);
}

static int	draw_cases(t_env *e, char *raw, int j)
{
	int		index;

	index = 0;
	while (index < e->game->width)
	{
		draw_case(e, index, j, raw[index]);
		index++;
	}
	return (1);
}

int			get_map(t_env *e, t_game *g)
{
	int		index;
	char	*line;

	index = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	ft_strdel(&line);
	init_img(e);
	while (index < g->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		ft_strdel(&(g->map[index]));
		g->map[index] = ft_strsub(line, 4, g->width);
		draw_cases(e, g->map[index], index);
		find_adv_last_piece(e, g->testmap[index], g->map[index], index);
		ft_strdel(&(g->testmap[index]));
		g->testmap[index] = ft_strdup(g->map[index]);
		ft_fprintf(g->fd, "line read :%3d %s\n", index, g->map[index]);
		index++;
		ft_strdel(&line);
	}
	return (1);
}
