/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/27 16:58:50 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static int	handle_key(int keycode, void *data)
{
	t_env *e;

	e = (t_env *)data;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 69 && e->delay + 1000 < 2147483647)
		e->delay += 1000;
	else if (keycode == 78 && e->delay - 1000 > 0)
		e->delay -= 1000;
	return (0);
}

static int	get_board_size(t_game *g, char *line)
{
	g->height = ft_atoi(line + 8);
	g->width = ft_atoi(ft_strchr(line + 8, ' ') + 1);
	return (1);
}

static int	init_game(t_env *e, t_game *g, char *line)
{
	e->game = g;
	g->fd = open("test.txt", O_WRONLY | O_APPEND);
	if (!get_board_size(g, line))
		return (0);
	set_env_delta(e);
	if (!(g->map = (char **)ft_memalloc(g->height * sizeof(char *))))
		return (0);
	return (1);
}

static int	visual_core(void *p)
{
	t_env		*e;
	t_game		*g;
	char		*line;

	e = (t_env *)p;
	g = e->game;
	if (get_next_line(0, &line) <= 0)
		return (0);
	if (!ft_strncmp(line, "Plateau", 7))
	{
		init_img(e);
		if (!e->game->width)
			init_game(e, g, line);
		get_map(e, g);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 150, 150);
		usleep(e->delay);
	}
	else if (!ft_strncmp(line, "==", 2))
		set_score(e, g, line);
	ft_strdel(&line);
	return (1);
}

int			main(void)
{
	t_env		e;
	t_game		g;

	ft_bzero(&g, sizeof(t_game));
	if (!init_env(&e, &g))
		return (1);
	mlx_loop_hook(e.mlx, visual_core, (void *)&e);
	mlx_key_hook(e.win, handle_key, (void *)&e);
	mlx_loop(e.mlx);
	return (0);
}
