/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 09:04:03 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 19:31:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			set_deltas(t_info *info, int i, int j)
{
	if (i < info->minx)
		info->minx = i;
	if (i > info->maxx)
		info->maxx = i;
	if (j < info->miny)
		info->miny = j;
	if (j > info->maxy)
		info->maxy = j;
	return (1);
}

static int			set_center(t_info *info)
{
	info->cx = info->minx + (info->maxx - info->minx) / 2;
	info->cy = info->miny + (info->maxy - info->miny) / 2;
	return (1);
}

int					set_info_helper(t_game *g, int i, int j)
{
	if (g->map[j][i] == g->adv)
		set_deltas(&(g->ainfo), i, j);
	else if (g->map[j][i] == g->me)
		set_deltas(&(g->myinfo), i, j);
	return (1);
}

int					set_info(t_game *g)
{
	parse_map(g, set_info_helper);
	set_center(&(g->myinfo));
	set_center(&(g->ainfo));
	ft_fprintf(g->fd, "myinfo minx%d maxx%d miny%d maxy%d cx %d cy %d\n", g->myinfo.minx, g->myinfo.maxx, g->myinfo.miny, g->myinfo.maxy, g->myinfo.cx, g->myinfo.cy);
	ft_fprintf(g->fd, "ainfo minx%d maxx%d miny%d maxy%d cx %d cy %d\n", g->ainfo.minx, g->ainfo.maxx, g->ainfo.miny, g->ainfo.maxy, g->ainfo.cx, g->ainfo.cy);
	ft_fprintf(g->fd, "mystart %d %d   his start %d %d\n", g->mystart.x, g->mystart.y, g->aistart.x, g->aistart.y);
	return (1);
}
