/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:20:36 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 20:03:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

int			set_env_delta(t_env *e)
{
	int		w;
	int		h;

	w = (W_WIDTH - 300) / e->game->width - 1;
	h = (W_HEIGHT - 300) / e->game->height - 1;
	e->d = (w <= h ? w : h);
	return (1);
}

int			init_env(t_env *e, t_game *g)
{
	ft_bzero(e, sizeof(t_env));
	ft_bzero(g, sizeof(t_game));
	e->game = g;
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "filler")))
		return (0);
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

int			draw_case(t_env *e, int i, int j, char v)
{
	t_point		p;

	ft_fprintf(e->game->fd, "draw case %d %d\n", i, j);
	p.x = i;
	p.y = j;
	if (v == 'O')
		put_case_to_img(e, &p, 0xFF0000);
	else if (v == 'X')
		put_case_to_img(e, &p, 0x008000);
	else if (v == '.')
		put_case_to_img(e, &p, 0xc8c8c8);
	else if (v == 'o')
		put_case_to_img(e, &p, 0xFF901E);
	else if (v == 'x')
		put_case_to_img(e, &p, 0x00FF00);
	return (1);
}

int			init_img(t_env *e)
{
	int			ed;

	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &ed);
	return (1);
}
