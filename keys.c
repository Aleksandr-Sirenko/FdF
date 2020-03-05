/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:53:58 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:57:56 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyiso(t_mlx *e)
{
	int i;
	int j;

	i = 0;
	e->zoom = 1;
	e->x1 = 0;
	e->y1 = 0;
	e->z1 = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x = e->mas[i][j].xx;
			e->mas[i][j].y = e->mas[i][j].yy;
			e->mas[i][j].z = e->mas[i][j].zz;
			j++;
		}
		i++;
	}
	mlx_clear_window(e->mlx, e->win);
	flat_dots(e);
	center_dots(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	keycavalier(t_mlx *e)
{
	int i;
	int j;

	i = 0;
	e->zoom = 1;
	e->x1 = 0;
	e->y1 = 0;
	e->z1 = 0;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x = e->mas[i][j].xx;
			e->mas[i][j].y = e->mas[i][j].yy;
			e->mas[i][j].z = e->mas[i][j].zz;
			j++;
		}
		i++;
	}
	mlx_clear_window(e->mlx, e->win);
	flat_dots2(e);
	center_dots(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}

int		deal_key(int key, t_mlx *e)
{
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
		return (0);
	}
	if (key == 49)
	{
		mlx_clear_window(e->mlx, e->win);
		center_dots(e);
		drawlines(e->mas, e, e->c);
		legend(e);
	}
	return (0);
}

int		rotate(int key, t_mlx *e)
{
	if (key == 24 || key == 69)
		keyplus(e);
	if (key == 27 || key == 78)
		keyminus(e);
	if (key == 13)
		up(e);
	if (key == 1)
		down(e);
	if (key == 0)
		left(e);
	if (key == 2)
		right(e);
	if (key == 7)
		rotate_x(e);
	if (key == 16)
		rotate_y(e);
	if (key == 6)
		rotate_z(e);
	if (key == 18)
		keyiso(e);
	if (key == 19)
		keycavalier(e);
	return (0);
}

int		exit_x(void)
{
	exit(1);
	return (0);
}
