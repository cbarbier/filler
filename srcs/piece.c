/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:42:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/10 17:27:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_offset(t_piece *p)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < p->h)
	{
		i = 0;
		if ((tmp = ft_strchr(p->map[j], '*')) && p->dy < 0)
			p->dy = j;
		else if (p->dy >= 0 && !tmp)
			p->dh = j;
		while (i < p->w)
		{
			if (p->map[j][i] == '*')
			{
				if (i < p->dx)
					p->dx = i;
				if (i > p->dw)
					p->dw = i;
			}
			i++;
		}
		j++;
	}
}

static int	fill_piece_map(t_game *g)
{
	int		index;
	char	*line;

	index = 0;
	while (index < g->piece->h)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		g->piece->map[index] = line;
		ft_fprintf(g->fd, "piece line %d %s\n", index, g->piece->map[index]);
		index++;
	}
	return (1);
}

int			get_pieces(t_game *g, char *line)
{
	t_piece		*p;

	p = g->piece;
	ft_bzero(p, sizeof(t_piece));
	p->h = ft_atoi(line + 6);
	p->w = ft_atoi(ft_strrchr(line, ' ') + 1);
	ft_fprintf(g->fd, "piece h%d w%d\n", p->h, p->w);
	if (!(p->map = (char **)ft_memalloc(p->h * sizeof(char))))
		return (0);
	if (!fill_piece_map(g))
		return (0);
	p->dx = p->w;
	p->dy = -1;
	p->dh = p->h - 1;
	set_offset(p);
	p->dh = p->dh - p->dy + 1;
	p->dw = p->dw - p->dx + 1;
	ft_fprintf(g->fd, "new piece h%d w%d dx%d dy%d dw%d dh%d\n", p->h, p->w, p->dx, p->dy, p->dw, p->dh);
	return (1);
}
