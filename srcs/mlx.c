/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:20:36 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/21 19:31:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	set_delta(t_game *g, t-env *e)
{
	int		w;
	int		h;

	w = (W_WIDTH - 300) / g->width - 1;
	h = (W_HEIGHT - 300) / g->height - 1;
	e->d = (w <= h ? w : h);
}

int			init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "filler")))
		return (0);
	return (1);
}

static int	put_case_to_img(t_game *g, t_env *e, int i, int j)
{
	int		dx;
	int		dy;

	dy = 0;
	dx = 0;
	while (dy < e->d)
	{
		dx = 0;
		while (dx < e->d)
		{
			put_pxl_img(g, e, i + dx, j + dy);
			dx++;
		}
		dy++;
	}
	return (1);
}

static int	draw_map(t_game *g, t_env *e)
{
	t_point		p;

	while (p.y < g->height)
	{
		p.x = 0;
		while (p.x < g->width)
		{
			if (!put_case_to_img(g, e, p))
				return (0);	
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int			put_map(t_game *g, t_env *e)
{
	int			ed;

	mlx_clear_window(e->mlx, e->win);
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	data = mlx_get_data_addr(e->img, &(f->bpp), &(f->sizeline), &ed);
	draw_map(g, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (1);
}
