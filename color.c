/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:02:39 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/04 20:03:10 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	changecolour(t_mlx *e)
{
	int i;
	int j;
	int max;
	int min;

	max = max_z(e->mas, e->c);
	min = min_z(e->mas, e->c);
	i = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			if (e->mas[i][j].z == min)
				e->mas[i][j].color = GREEN;
			else if (e->mas[i][j].z == max)
				e->mas[i][j].color = WH;
			else
				e->mas[i][j].color = gc2(min, max, e->mas[i][j].z);
			j++;
		}
		i++;
	}
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		gc(t_point current, t_point start, t_point end, t_line delta)
{
	int		red;
	int		green;
	int		blue;
	double	p;

	if (current.color == end.color)
		return (current.color);
	if (delta.deltax > delta.deltay)
		p = percent(start.x, end.x, current.x);
	else
		p = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}

int		gc2(int min, int max, int current)
{
	int		red;
	int		green;
	int		blue;
	double	p;

	p = percent(min, max, current);
	red = get_light((GREEN >> 16) & 0xFF, (RED >> 16) & 0xFF, p);
	green = get_light((GREEN >> 8) & 0xFF, (RED >> 8) & 0xFF, p);
	blue = get_light(GREEN & 0xFF, RED & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}
