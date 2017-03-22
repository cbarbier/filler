/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 17:51:42 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	set_start(t_game *g, int i, int j)
{
	if (g->map[j][i] == g->adv)
	{
		g->aistart.x = i;
		g->aistart.y = j;	
	}
	else if (g->map[j][i] == g->me)
	{	
		g->mystart.x = i;
		g->mystart.y = j;	
	}
	return (1);
}

static int	free_piece(t_game *g)
{
	int			index;

	index = 0;
	while (index < g->piece->h)
		free(g->piece->map[index++]); free(g->piece->map);
	g->piece->map = 0;
	return (1);
}

static int	put_piece(t_game *g)
{
	t_piece		*p;

	p = g->piece;
	ft_fprintf(g->fd, "put %d %d\n", g->sol.y - p->dy, g->sol.x - p->dx);
	ft_printf("%d %d\n", g->sol.y - p->dy, g->sol.x - p->dx);
	return (1);
}

static int	filler_core(void *p)
{
	t_env		*e;
	t_game		*g;
	char		*line;

	e = (t_env *)p;
	g = e->game;
	if (get_next_line(0, &line) <= 0)
		return (0);
	if (!ft_strncmp(line, "Plateau", 7))
		get_map(e, g);
	else if (!ft_strncmp(line, "Piece", 5))
	{
		set_info(g);
		ft_bzero(&(g->sol), sizeof(t_info));
		get_pieces(g, line);
		compute_piece(g);
		draw_last_piece(e);
		put_piece(g);
		free_piece(g);
		g->loopcount++;
		mlx_put_image_to_window(e->mlx, e->win, e->img, 150, 150);
		usleep(50000);
	}
	ft_strdel(&line);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env		e;
	t_game		g;

	if (!argv[argc - 1])
		return (0);
	if (!init_env(&e, &g))
		return (1);
	if (!parse_map(&g, set_start))
		return (0);
	ft_fprintf(g.fd, "initialized\n");
	mlx_put_image_to_window(e.mlx, e.win, e.img, 150, 150);
	mlx_loop_hook(e.mlx, filler_core, (void *)&e);
	mlx_loop(e.mlx);
	return (0);
}
