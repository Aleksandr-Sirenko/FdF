/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mashtab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:29:39 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/17 21:48:00 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		calculate_m(t_point **mas, t_count c)
{
	int max;

	max = 1;
	if (c.lines > c.points)
		max = c.lines;
	else
		max = c.points;
	if (max_z(mas, c) > max)
		max = max_z(mas, c);
	if (SCREEN_W > SCREEN_H)
		max = (SCREEN_H / 1.5) / max;
	else
	{
		max = (SCREEN_W / 1.5) / max;
	}
	return (max);
}

void	mashtab(t_mlx *e)
{
	int i;
	int j;

	i = 0;
	if (fabs(e->mas[0][0].x - e->mas[0][1].x) < SCREEN_W)
	{
		e->zoom++;
		while (i < e->c.lines)
		{
			j = 0;
			while (j < e->c.points)
			{
				e->mas[i][j].x = e->mas[i][j].x * ZOOMP;
				e->mas[i][j].y = e->mas[i][j].y * ZOOMP;
				j++;
			}
			i++;
		}
	}
}

void	mashtab2(t_mlx *e)
{
	int i;
	int j;

	i = 0;
	if (fabs(e->mas[0][0].x - e->mas[0][1].x) > 0.01)
	{
		e->zoom--;
		while (i < e->c.lines)
		{
			j = 0;
			while (j < e->c.points)
			{
				e->mas[i][j].x = e->mas[i][j].x * ZOOMM;
				e->mas[i][j].y = e->mas[i][j].y * ZOOMM;
				j++;
			}
			i++;
		}
	}
}

void	change_m(t_mlx *e)
{
	int i;
	int j;

	i = 0;
	e->cam.x = 0;
	e->cam.y = 0;
	e->zoom = 1;
	e->m = calculate_m(e->mas, e->c);
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x = e->mas[i][j].x * e->m;
			e->mas[i][j].y = e->mas[i][j].y * e->m;
			e->mas[i][j].z = e->mas[i][j].z * e->m;
			e->mas[i][j].xx = e->mas[i][j].x;
			e->mas[i][j].yy = e->mas[i][j].y;
			e->mas[i][j].zz = e->mas[i][j].z;
			j++;
		}
		i++;
	}
}
