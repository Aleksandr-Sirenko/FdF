/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:27:03 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:29:22 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_x(t_point **mas, t_count c)
{
	int i;
	int j;
	int maxx;

	maxx = 0;
	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (mas[i][j].x > maxx)
				maxx = mas[i][j].x;
			j++;
		}
		i++;
	}
	return (maxx);
}

int		max_y(t_point **mas, t_count c)
{
	int i;
	int j;
	int maxy;

	maxy = 0;
	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (mas[i][j].y > maxy)
				maxy = mas[i][j].y;
			j++;
		}
		i++;
	}
	return (maxy);
}

int		min_x(t_point **mas, t_count c)
{
	int i;
	int j;
	int maxx;

	maxx = 2147483647;
	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (mas[i][j].x < maxx)
				maxx = mas[i][j].x;
			j++;
		}
		i++;
	}
	return (maxx);
}

int		min_y(t_point **mas, t_count c)
{
	int i;
	int j;
	int maxy;

	maxy = 2147483647;
	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (mas[i][j].y < maxy)
				maxy = mas[i][j].y;
			j++;
		}
		i++;
	}
	return (maxy);
}
