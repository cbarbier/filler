/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/09 17:13:53 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct	s_piece
{
	int		w;
	int		h;
	int		dx;
	int		dy;
	int		dw;
	int		dh;
	char	**map;
}				t_piece;
typedef	struct	s_game
{
	int		fd; // to delete 
	int		player;
	char	me;
	char	adv;
	int		width;
	int		height;
	t_piece	piece[1];
	char	**map;
}				t_game;

int			init_game(t_game *g);
int			lets_play(t_game *g);
int			get_pieces(t_game *g, char *line);
int			get_map(t_game *g);
int			put_piece(t_game *g);
#endif
