/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/16 16:25:01 by cbarbier         ###   ########.fr       */
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

static int	is_target_reached(t_game *g)
{
	t_info *t;
	t_info *m;
	int		count;

	t = &(g->advpos);
	m = &(g->myinfo);
	count = 0;
	if (m->minx < t->minx)
		count++;
	if (m->maxx > t->maxx)
		count++;
	if (m->miny < t->miny)
		count++;
	if (m->maxx > t->maxx)
		count++;
	return (count == 0 ? 0 : 1);
}

static int	find_adv_last_piece(t_game *g, char *lastr, char *newr, int raw)
{
	int		index;

	index = 0;
	while (index < g->width)
	{
		if (lastr[index] != g->adv && newr[index] == g->adv)
		{
			g->advpos.x = index;
			g->advpos.y = raw;
			return (1);
		}
		index++;
	}
	return (0);
}

int			get_map(t_game *g)
{
	int		index;
	char	*line;

	index = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	ft_strdel(&line);
	while (index < g->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		ft_strdel(&(g->map[index]));
		g->map[index] = ft_strsub(line, 4, g->width);
		if (g->testmap[index] && is_target_reached(g))
			find_adv_last_piece(g, g->testmap[index], g->map[index], index);
		ft_strdel(&(g->testmap[index]));
		g->testmap[index] = ft_strdup(g->map[index]);
		ft_fprintf(g->fd, "line read :%3d %s\n", index, g->map[index]);
		index++;
		ft_strdel(&line);
	}
	return (1);
}
