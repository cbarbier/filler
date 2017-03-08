/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/08 15:39:06 by cbarbier         ###   ########.fr       */
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
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, "Piece", 5))
			get_pieces(&g, line);
		ft_fprintf(g.fd, "%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
