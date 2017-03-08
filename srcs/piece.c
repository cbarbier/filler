/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:42:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/08 15:46:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	fill_piece_map(t_game *g)
{
	int		index;
	char	*line;

	index = 0;
	while (index < g->piece->h)
	{
		if (get_next_line(0, &line) < 0)
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
	ft_fprintf(g->fd, "new piece h%d w%d\n", p->h, p->w);
	if (!(p->map = (char **)ft_memalloc(p->h * sizeof(char))))
		return (0);
	if (!fill_piece_map(g))
		return (0);
	return (1);
}
