/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:26:09 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/27 16:58:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

void		set_score(t_env *e, t_game *g, char *line)
{
	int			sp1;
	int			sp2;

	(void)g;
	sp1 = ft_atoi(line + 10);
	if (get_next_line(0, &line) <= 0)
		return ;
	sp2 = ft_atoi(line + 10);
	if (sp1 > sp2)
		mlx_string_put(e->mlx, e->win, W_WIDTH / 2, W_HEIGHT / 2, 0xFFFFFF,
				"P1 WON");
	else
		mlx_string_put(e->mlx, e->win, W_WIDTH / 2, W_HEIGHT / 2, 0xFFFFFF,
				"P2 WON");
}

void		put_pxl_img(t_env *e, int x, int y, unsigned int c)
{
	char		*d;

	d = (e->data + (e->sizeline * y + x * e->bpp / 8));
	d[0] = (c & 0xFF0000) >> 16;
	d[1] = (c & 0xFF00) >> 8;
	d[2] = (c & 0xFF);
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

	if (get_next_line(0, &line) <= 0)
		return (0);
	index = 0;
	while (index < g->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		ft_strdel(&(g->map[index]));
		g->map[index] = ft_strsub(line, 4, g->width);
		draw_cases(e, g->map[index], index);
		index++;
		ft_strdel(&line);
	}
	return (1);
}
