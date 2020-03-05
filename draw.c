/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:35:58 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/04 17:04:35 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_point a, t_point b, t_mlx *e)
{
	e->s.x = a.x;
	e->s.y = a.y;
	e->s.color = a.color;
	e->l.deltax = fabs(round(b.x) - round(a.x));
	e->l.deltay = fabs(round(b.y) - round(a.y));
	e->l.signx = round(a.x) < round(b.x) ? 1 : -1;
	e->l.signy = round(a.y) < round(b.y) ? 1 : -1;
	e->l.error = e->l.deltax - e->l.deltay;
	mlx_pixel_put(e->mlx, e->win, T(b.x), T(b.y), gc(b, e->s, b, e->l));
	while (round(a.x) != round(b.x) || round(a.y) != round(b.y))
	{
		mlx_pixel_put(e->mlx, e->win, T(a.x), T(a.y), gc(a, e->s, b, e->l));
		e->l.error2 = e->l.error * 2;
		if (e->l.error2 > -e->l.deltay)
		{
			e->l.error -= e->l.deltay;
			a.x += e->l.signx;
		}
		if (e->l.error2 < e->l.deltax)
		{
			e->l.error += e->l.deltax;
			a.y += e->l.signy;
		}
	}
}

void	drawlines(t_point **m, t_mlx *e, t_count c)
{
	int i;
	int j;

	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (j < c.points - 1)
				drawline(m[i][j], m[i][j + 1], e);
			if (i < c.lines - 1)
				drawline(m[i][j], m[i + 1][j], e);
			j++;
		}
		i++;
	}
}

void	draw_points(t_point **mas, t_mlx *e, t_count c)
{
	int i;
	int j;

	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			mlx_pixel_put(e->mlx, e->win, mas[i][j].x,
					mas[i][j].y, mas[i][j].color);
			j++;
		}
		i++;
	}
}
