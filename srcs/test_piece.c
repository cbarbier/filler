/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:37:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/23 19:18:28 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print_info(t_game *g, t_info *i)
{
	ft_fprintf(g->fd, "x %d - %d\ny %d - %d\nd x%d y%d\nc x%d y%d\n", i->minx, i->maxx, i->miny, i->maxy, i->dx, i->dy, i->cx, i->cy);
}

static int		update_piece(t_game *g, int x, int y, int add)
{
	int		i;
	int		j;
	t_piece	*p;

	p = g->piece;
	j = 0;
	while (j < p->dh)
	{
		i = 0;
		while (i < p->dw)
		{
			if (p->map[j][i] == '*')
				if (add || (!add && g->map[y + j][x + i] != g->me))
					g->testmap[y + j][x + i] = (add ? g->me : '.');
			i++;
		}
		j++;
	}
	return (1);
}

static int		set_deltas(t_game *g, t_info *tmp, int i, int j)
{
	t_info		*myinfo;

	myinfo = &(g->myinfo);
	tmp->minx = i < myinfo->minx ? i : myinfo->minx;
	tmp->maxx = i > myinfo->maxx ? i : myinfo->maxx;
	tmp->miny = j < myinfo->miny ? j : myinfo->miny;
	tmp->maxy = j > myinfo->maxy ? j : myinfo->maxy;
	return (1);
}

static int		distance(t_info *a, t_info *b)
{
	return (abs(a->x - b->x) + abs(a->y - b->y));
}

static int		sol_compare(t_game *g, t_info *tmpsol)
{
	int		i;
	int		j;
	t_piece	*p;
	t_info	info;

	p = g->piece;
	j = 0;
	while (j < p->dh)
	{
		i = 0;
		while (i < p->dw)
		{
			if (g->testmap[tmpsol->y + j][tmpsol->x + i] == g->me)
				set_deltas(g, tmpsol, tmpsol->x + i, tmpsol->y + j);
			i++;
		}
		j++;
	}
	info.x = g->width / 2;
	info.y = g->height / 2;
	tmpsol->dy = tmpsol->maxy - tmpsol->miny + 1;
	tmpsol->dx = tmpsol->maxx - tmpsol->minx + 1;
	tmpsol->avg = (g->height - tmpsol->maxy + g->width - tmpsol->maxx + tmpsol->miny + tmpsol->minx) / 4.0;
//	return (distance(&(g->sol), &(g->advpos)) - distance(tmpsol, &(g->advpos)));
	return (distance(&(g->sol), &info) - distance(tmpsol, &info));
}

int				test_piece(t_game *g, int x, int y, int *count)
{
	t_info		tmp;

	ft_bzero(&tmp, sizeof(t_info));
	tmp.maxx = g->width;
	tmp.maxy = g->height;
	tmp.x = x;
	tmp.y = y;
	update_piece(g, x, y, 1);
	ft_fprintf(g->fd, "add on map:\n");
//	put_map(g, g->testmap);
	if (!*count || (sol_compare(g, &tmp)) > 0)
		g->sol = tmp;
	update_piece(g, x, y, 0);
	ft_fprintf(g->fd, "remove from map:\n");
//	put_map(g, g->testmap);
	print_info(g, &tmp);
	*count = *count + 1;
	return (1);
}
