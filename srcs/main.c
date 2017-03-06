/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:39:04 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/06 14:42:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(int argc, char **argv)
{
	char		*line;

	if (!argv[argc - 1])
		return (0);
	while (get_next_line(0, &line))
	{
		ft_fprintf(open("test.txt", O_WRONLY | O_APPEND), "%s\n", line);
	}
	return (0);
}
