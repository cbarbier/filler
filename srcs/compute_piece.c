/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:47:22 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/27 16:41:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	can_put(t_game *g, int i, int j)
{
	int			x;
	int			y;
	t_piece		*p;
	int			count;

	count = 0;
	p = g->piece;
	y = 0;
	while (count <= 1 && y < p->dh)
	{
		x = 0;
		while (count <= 1 && x < p->dw)
		{
			if (p->map[p->dy + y][p->dx + x] == '*' &&
					g->map[j + y][i + x] == g->me)
				count++;
			if (count > 1 || (p->map[p->dy + y][p->dx + x] == '*' &&
						g->map[j + y][i + x] == g->adv))
				return (0);
			x++;
		}
		y++;
	}
	return (count == 1 ? 1 : 0);
}

int			compute_piece(t_game *g)
{
	int		i;
	int		j;
	t_piece	*p;
	int		count;

	p = g->piece;
	j = 0;
	count = 0;
	while (j + p->dh <= g->height)
	{
		i = 0;
		while (i + p->dw <= g->width)
		{
			if (can_put(g, i, j))
			{
				test_piece(g, i, j, &count);
			}
			i++;
		}
		j++;
	}
	return (1);
}
