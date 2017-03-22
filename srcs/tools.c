/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:19:03 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 17:47:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				put_pxl_img(t_env *e, int x, int y, unsigned int c)
{
	char		*d;

	d = (e->data + (e->sizeline * y + x * e->bpp / 8));
	d[0] = (c & 0xFF0000) >> 16;
	d[1] = (c & 0xFF00) >> 8;
	d[2] = (c & 0xFF);
}

int					draw_last_piece(t_env *e)
{
	t_game		*g;
	int			j;
	int			i;

	g = e->game;
	j = 0;
	while (j < g->piece->dh)
	{
		i = 0;
		while (i < g->piece->dw)	
		{
			if (g->piece->map[j][i] == '*')
				draw_case(e, g->sol.x + i, g->sol.y + j, g->me + 32);
			ft_fprintf(g->fd, "lastpiece pos %d %d %c#####################################\n", g->sol.x + i, g->sol.y + j, g->me + 32);
			i++;
		}
		j++;
	}
	return (1);
}
