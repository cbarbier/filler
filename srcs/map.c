/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/09 18:40:03 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_map(t_game *g)
{
	int		index;
	char	*line;

	index = 0;

	if (get_next_line(0, &line) < 0)
		return (0);
	ft_strdel(&line);
	while (index < g->height)
	{
		if (get_next_line(0, &line) < 0)
			return (0);
		ft_strdel(&(g->map[index]));
		g->map[index] = ft_strsub(line, 4, g->width);
		ft_fprintf(g->fd, "line read : %s\n", g->map[index]);
		index++;
		ft_strdel(&line);
	}
	return (1);
}
