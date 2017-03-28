/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:37:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/28 18:26:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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

static int		set_adj(t_game *g, t_info *tmp, int i, int j)
{
	if (j && g->map[j - 1][i] == g->adv)
		tmp->adj += g->aistart.y < g->mystart.y ? 1 : 2;
	if (j < g->height - 1 && g->map[j + 1][i] == g->adv)
		tmp->adj += g->aistart.y > g->mystart.y ? 1 : 2;
	if (i && g->map[j][i - 1] == g->adv)
		tmp->adj++;
	if (i < g->width - 1 && g->map[j][i + 1] == g->adv)
		tmp->adj++;
	return (1);
}

static int		sol_compare(t_game *g, t_info *tmpsol)
{
	int				i;
	int				j;
	t_piece			*p;

	p = g->piece;
	j = 0;
	while (j < p->dh)
	{
		i = 0;
		while (i < p->dw)
		{
			if (g->testmap[tmpsol->y + j][tmpsol->x + i] == g->me)
			{
				set_deltas(g, tmpsol, tmpsol->x + i, tmpsol->y + j);
				set_adj(g, tmpsol, tmpsol->x + i, tmpsol->y + j);
			}
			i++;
		}
		j++;
	}
	tmpsol->dy = tmpsol->maxy - tmpsol->miny + 1;
	tmpsol->dx = tmpsol->maxx - tmpsol->minx + 1;
	return (!tmpsol->adj ? -1 : tmpsol->adj - g->sol.adj);
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
	if (!*count || (sol_compare(g, &tmp)) > 0)
		g->sol = tmp;
	update_piece(g, x, y, 0);
	*count = *count + 1;
	return (1);
}
