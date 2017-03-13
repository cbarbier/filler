/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:37:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/13 11:57:58 by cbarbier         ###   ########.fr       */
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
			if (p->map[j][i] == '*' )
				if (add || (!add && g->map[y + j][x + i] == '*'))
					g->testmap[y + j][x + i] = (add ? g->me : '.');
			i++;
		}
		j++;
	}
	return (1);
}

static int		set_deltas(int	*d, int i, int j)
{
	if (i < d[0])
		d[0] = i;
	if (i > d[2])
		d[2] = i;
	if (j < d[1])
		d[1] = j;
	if (j > d[3])
		d[3] = j;
	return (1);
}

static int		sol_compare(t_game *g, int *d, t_sol *tmpsol)
{
	int		i;
	int		j;
	t_piece	*p;

	p = g->piece;
	j = 0;
	while (j < g->height)
	{
		i = 0;
		while (i < g->width)
		{
			if (g->testmap[j][i] == g->me)
				set_deltas(d, i, j);
			i++;
		}
		j++;
	}
	tmpsol->dy = d[3] - d[1] + 1;
	tmpsol->dx = d[2] - d[0] + 1;
	return (tmpsol->dy - g->sol.dy);
}

int				test_piece(t_game *g,  int x, int y)
{
	int		deltas[4];
	t_sol	tmp;

	deltas[0] = g->width;
	deltas[1] = g->height;
	deltas[2] = 0;
	deltas[3] = 0;
	update_piece(g, x, y, 1);
	tmp.x = x;
	tmp.y = y;
	if ((sol_compare(g, deltas, &tmp)) > 0)
		g->sol = tmp;
	ft_fprintf(g->fd, "delta xmin%d ymin%d xmax%d ymax%d\ndx %d dy %d\n", deltas[0], deltas[1], deltas[2], deltas[3], tmp.dx, tmp.dy);
	update_piece(g, x, y, 0);
	return (1);
}
