/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:51:22 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:47:40 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H

# define _FDF_H
# define SCREEN_W 2000
# define SCREEN_H 1000
# define R 0.0174533
# define MOVEC 8
# define T round
# define ZOOMP 1.01
# define ZOOMM 0.99
# define WH 0xFFFFFF
# define GREEN 0x177245
# define RED 0xDC143C
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "get_next_line.h"
# include <math.h>

typedef struct	s_camera {
	double			x;
	double			y;
}				t_camera;

typedef struct	s_point {
	double			xx;
	double			yy;
	double			zz;
	double			x;
	double			y;
	double			z;
	int				color;
}				t_point;

typedef struct	s_read {
	int		fd;
	char	*line;
	char	**lines;
	int		i;
	int		z;
}				t_read;

typedef struct	s_line
{
	double	deltax;
	double	deltay;
	int		signx;
	int		signy;
	int		error;
	int		error2;
}				t_line;

typedef struct	s_count {
	int				lines;
	int				points;
	int				dots;
}				t_count;

typedef struct	s_mlx
{
	int			m;
	void		*mlx;
	void		*win;
	t_point		**mas;
	t_count		c;
	t_camera	cam;
	t_line		l;
	t_point		s;
	int			x1;
	int			y1;
	int			z1;
	int			zoom;
}				t_mlx;

void			center_dots(t_mlx *e);
void			center_dots2(t_mlx *e);
void			flat_dots(t_mlx *e);
void			flat_dots2(t_mlx *e);
t_point			**read_file(char *filename);
int				count_dots(char *filename);
int				count_lines(char *filename);
t_count			count_lp(char *filename);
int				count_points(char *filename);
void			draw_points(t_point **mas, t_mlx *e, t_count c);
void			drawlines(t_point **m, t_mlx *e, t_count c);
void			drawline(t_point a, t_point b, t_mlx *e);
int				max_x(t_point **mas, t_count c);
int				max_y(t_point **mas, t_count c);
int				max_z(t_point **mas, t_count c);
int				min_z(t_point **mas, t_count c);
int				min_x(t_point **mas, t_count c);
int				min_y(t_point **mas, t_count c);
void			mashtab(t_mlx *e);
void			mashtab2(t_mlx *e);
int				calculate_m(t_point **mas, t_count c);
void			change_m(t_mlx *e);
void			down(t_mlx *e);
void			up(t_mlx *e);
void			left(t_mlx *e);
void			right(t_mlx *e);
int				deal_key(int key, t_mlx *e);
int				exit_x(void);
void			rotate_x(t_mlx *e);
void			rotate_y(t_mlx *e);
void			rotate_z(t_mlx *e);
int				rotate(int key, t_mlx *e);
void			legend(t_mlx *e);
int				validate(char *filename);
void			changecolour(t_mlx *e);
int				get_light(int start, int end, double percentage);
double			percent(int start, int end, int current);
int				gc(t_point current, t_point start, t_point end, t_line delta);
int				gc2(int min, int max, int current);
void			keyplus(t_mlx *e);
void			keyminus(t_mlx *e);

#endif
