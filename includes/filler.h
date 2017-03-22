/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/22 11:40:11 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define W_WIDTH	1000
# define W_HEIGHT 	1000
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_info
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	double	avg;
	int		cx;
	int		cy;
	int		minx;
	int		maxx;
	int 	miny;
	int		maxy;
}				t_info;

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
	char	**testmap;
	t_info	myinfo;
	t_info	ainfo;
	t_info	sol;
	t_info	advpos;
	int		loopcount;
	t_info	mystart;
	t_info	aistart;
}				t_game;

typedef struct	s_env
{
	t_game	*game;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		d;
}				t_env;

int			init_game(t_game *g);
int			lets_play(t_game *g);
int			get_pieces(t_game *g, char *line);
int			get_map(t_game *g);
int			compute_piece(t_game *g);
int			test_piece(t_game *g,  int x, int y, int *count);
int			set_info(t_game *g);
int			put_map(t_game *g, char **m);
int			parse_map(t_game *g, int (*f)(t_game *, int, int));
void		put_pxl_img(t_env *e, int x, int y, unsigned int c);
int			init_env(t_env *env, t_game *g);
int			init_img(t_env *e);
int			draw_map(t_env *e);

#endif
