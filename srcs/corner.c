/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:32:10 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/28 18:15:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	set_corner_helper(t_game *g, int *c)
{
	if (c[0] > c[1] && c[0] > c[2] && c[0] > c[3])
	{
		g->corner.x = 0;
		g->corner.y = 0;
	}
	if (c[1] > c[0] && c[1] > c[2] && c[1] > c[3])
	{
		g->corner.x = g->width;
		g->corner.y = 0;
	}
	if (c[2] > c[0] && c[2] > c[1] && c[2] > c[3])
	{
		g->corner.x = g->width;
		g->corner.y = g->height;
	}
	if (c[3] > c[0] && c[3] > c[1] && c[3] > c[2])
	{
		g->corner.x = 0;
		g->corner.y = g->height;
	}
}

int			set_corner(t_game *g)
{
	int		c[4];

	c[0] = dist_xy(&(g->sol), 0, 0);
	c[1] = dist_xy(&(g->sol), g->width, 0);
	c[2] = dist_xy(&(g->sol), g->width, g->height);
	c[3] = dist_xy(&(g->sol), 0, g->height);
	set_corner_helper(g, c);
	return (1);
}
