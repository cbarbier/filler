/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:20:36 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 12:01:12 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	set_delta(t_env *e)
{
	int		w;
	int		h;

	w = (W_WIDTH - 300) / e->game->width - 1;
	h = (W_HEIGHT - 300) / e->game->height - 1;
	e->d = (w <= h ? w : h);
	ft_fprintf(e->game->fd, "############################ delta is %d\n", e->d);
	return (1);
}

int			init_env(t_env *e, t_game *g)
{
	ft_bzero(e, sizeof(t_env));
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "filler")))
		return (0);
	e->game = g;
	set_delta(e);
	return (1);
}

static int	put_case_to_img(t_env *e, t_point *p, unsigned int c)
{
	int		dx;
	int		dy;

	dy = 0;
	while (dy < e->d)
	{
		dx = 0;
		while (dx < e->d)
		{
			put_pxl_img(e, p->x * e->d + dx, p->y * e->d + dy, c);
			dx++;
		}
		dy++;
	}
	return (1);
}

int			draw_map(t_env *e)
{
	t_point		p;
	char		v;

	ft_fprintf(e->game->fd, "draw map\n");
	p.y = 0;
	while (p.y < e->game->height)
	{
		p.x = 0;
		while (p.x < e->game->width)
		{
			v = e->game->map[p.y][p.x];
			if (v == 'O') 
				put_case_to_img(e, &p, 0xFF0000);
		   	else if (v == 'X') 
				put_case_to_img(e, &p, 0x00FF00);
			else if (v == '.') 
				put_case_to_img(e, &p, 0xc8c8c8);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 150, 150);
	sleep(1);
	return (1);
}

int			init_img(t_env *e)
{
	int			ed;

	ft_fprintf(e->game->fd, "init img\n");
	mlx_clear_window(e->mlx, e->win);
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &ed);
	return (1);
}
