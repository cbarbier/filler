/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/15 12:55:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
		if (g->testmap[index])
			find_adv_last_piece(g, g->testmap[index], g->map[index], index);
		ft_strdel(&(g->testmap[index]));
		g->testmap[index] = ft_strdup(g->map[index]);
		ft_fprintf(g->fd, "line read :%3d %s\n", index, g->map[index]);
		index++;
		ft_strdel(&line);
	}
	return (1);
}
