/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/27 11:12:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# define W_WIDTH	1000
# define W_HEIGHT 	1000
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_player
{
	int		id;
	char	*name;
}				t_player;

typedef	struct	s_game
{
	int			fd; // to delete 
	int			width;
	int			height;
	char		**map;
	t_player	p1;
	t_player	p2;
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
	int		delay;
}				t_env;

int				get_map(t_env *e, t_game *g);
void			put_pxl_img(t_env *e, int x, int y, unsigned int c);
int				init_env(t_env *e, t_game *g);
int				init_img(t_env *e);
int				draw_case(t_env *e, int i, int j, char v);
int				set_env_delta(t_env *e);
void			set_score(t_env *e, t_game *g, char *line);

#endif
