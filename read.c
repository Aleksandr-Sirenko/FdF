/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:13:08 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:34:41 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		flat_dots2(t_mlx *e)
{
	int i;
	int j;
	int previous_x;
	int previous_y;

	e->x1 = 0;
	e->y1 = 0;
	e->z1 = 0;
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			previous_x = e->mas[i][j].xx;
			previous_y = e->mas[i][j].yy;
			e->mas[i][j].x = previous_x + e->mas[i][j].zz * cos(45 * R);
			e->mas[i][j].y = previous_y + e->mas[i][j].zz * sin(45 * R);
			j++;
		}
		i++;
	}
}

void		flat_dots(t_mlx *e)
{
	int i;
	int j;
	int previous_x;
	int previous_y;

	e->x1 = 0;
	e->y1 = 0;
	e->z1 = 0;
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			previous_x = e->mas[i][j].xx;
			previous_y = e->mas[i][j].yy;
			e->mas[i][j].x = (previous_x - previous_y) * cos(0.523599);
			e->mas[i][j].y = -e->mas[i][j].zz + (previous_x
					+ previous_y) * sin(0.523599);
			j++;
		}
		i++;
	}
}

void		center_dots(t_mlx *e)
{
	int deltax;
	int deltay;
	int i;
	int j;

	i = 0;
	e->cam.x = 0;
	e->cam.y = 0;
	deltax = (SCREEN_W - (max_x(e->mas, e->c) + min_x(e->mas, e->c))) / 2;
	deltay = (SCREEN_H - (max_y(e->mas, e->c) + min_y(e->mas, e->c))) / 2;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x = e->mas[i][j].x + deltax;
			e->mas[i][j].y = e->mas[i][j].y + deltay;
			j++;
		}
		i++;
	}
}

void		center_dots2(t_mlx *e)
{
	int deltax;
	int deltay;
	int i;
	int j;

	i = 0;
	deltax = (SCREEN_W - (max_x(e->mas, e->c) + min_x(e->mas, e->c))) / 2;
	deltay = (SCREEN_H - (max_y(e->mas, e->c) + min_y(e->mas, e->c))) / 2;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x = e->mas[i][j].x + deltax + e->cam.x;
			e->mas[i][j].y = e->mas[i][j].y + deltay + e->cam.y;
			j++;
		}
		i++;
	}
}

t_point		**read_file(char *filename)
{
	t_point	**mas;
	t_read	a;

	a.z = 0;
	mas = (t_point **)malloc(sizeof(t_point *) * count_lines(filename));
	a.fd = open(filename, O_RDONLY);
	while (get_next_line(a.fd, &a.line))
	{
		mas[a.z] = (t_point *)malloc(sizeof(t_point) * count_points(filename));
		a.i = 0;
		a.lines = ft_strsplit(a.line, ' ');
		while (a.lines[a.i])
		{
			mas[a.z][a.i].x = a.i;
			mas[a.z][a.i].y = a.z;
			mas[a.z][a.i].z = ft_atoi(a.lines[a.i]);
			free(a.lines[a.i]);
			a.i++;
		}
		free(a.lines);
		free(a.line);
		a.z++;
	}
	free(a.line);
	return (mas);
}
