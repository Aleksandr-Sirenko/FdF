/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:37:46 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/17 18:32:33 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mlx *e)
{
	int i;
	int j;
	int y;

	e->x1++;
	if (e->x1 == 360)
		e->x1 = 0;
	mlx_clear_window(e->mlx, e->win);
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			y = e->mas[i][j].y;
			e->mas[i][j].y = e->mas[i][j].y * cos(R) + e->mas[i][j].z * sin(R);
			e->mas[i][j].z = -y * sin(R) + e->mas[i][j].z * cos(R);
			j++;
		}
		i++;
	}
	center_dots2(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	rotate_y(t_mlx *e)
{
	int i;
	int j;
	int x;

	e->y1++;
	if (e->y1 == 360)
		e->y1 = 0;
	mlx_clear_window(e->mlx, e->win);
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			x = e->mas[i][j].x;
			e->mas[i][j].x = e->mas[i][j].x * cos(R) - e->mas[i][j].z * sin(R);
			e->mas[i][j].z = x * sin(R) + e->mas[i][j].z * cos(R);
			j++;
		}
		i++;
	}
	center_dots2(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	rotate_z(t_mlx *e)
{
	int i;
	int j;
	int x;

	e->z1++;
	if (e->z1 == 360)
		e->z1 = 0;
	mlx_clear_window(e->mlx, e->win);
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			x = e->mas[i][j].x;
			e->mas[i][j].x = e->mas[i][j].x * cos(R) + e->mas[i][j].y * sin(R);
			e->mas[i][j].y = -x * sin(R) + e->mas[i][j].y * cos(R);
			j++;
		}
		i++;
	}
	center_dots2(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}
