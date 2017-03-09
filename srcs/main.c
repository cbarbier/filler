/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/09 19:20:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
			get_pieces(&g, line);
			put_piece(&g);
		}
		ft_strdel(&line);
	}
	return (0);
}
