/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/14 10:39:32 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	free_piece(t_game *g)
{
	int			index;

	index = 0;
	while (index < g->piece->h)
		free(g->piece->map[index++]);
	free(g->piece->map);
	g->piece->map = 0;
	return (1);
}

static int	put_piece(t_game *g)
{
	t_piece		*p;

	p = g->piece;
	ft_printf("%d %d\n", g->sol.y - p->dy, g->sol.x - p->dx);
	ft_fprintf(g->fd, "put %d %d\n", g->sol.y - p->dy, g->sol.x - p->dx);
	return (1);
}

int			main(int argc, char **argv)
{
	char		*line;
	t_game		g;

	if (!argv[argc - 1])
		return (0);
	if (!init_game(&g))
		return (1);
	while (get_next_line(0, &line) > 0)
	{
		ft_fprintf(g.fd, "main %s\n", line);
		if (!ft_strncmp(line, "Plateau", 7))
			get_map(&g);
		else if (!ft_strncmp(line, "Piece", 5))
		{
			set_info(&g);
			ft_bzero(&(g.sol), sizeof(t_sol));
			get_pieces(&g, line);
			compute_piece(&g);
			put_piece(&g);
			free_piece(&g);
		}
		ft_strdel(&line);
	}
	return (0);
}
