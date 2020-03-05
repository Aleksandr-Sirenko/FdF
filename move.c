/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:16:57 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:17:21 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right(t_mlx *e)
{
	int i;
	int j;

	mlx_clear_window(e->mlx, e->win);
	i = 0;
	e->cam.x += MOVEC;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x += MOVEC;
			j++;
		}
		i++;
	}
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	left(t_mlx *e)
{
	int i;
	int j;

	mlx_clear_window(e->mlx, e->win);
	i = 0;
	e->cam.x -= MOVEC;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].x -= MOVEC;
			j++;
		}
		i++;
	}
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	up(t_mlx *e)
{
	int i;
	int j;

	mlx_clear_window(e->mlx, e->win);
	i = 0;
	e->cam.y -= MOVEC;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].y -= MOVEC;
			j++;
		}
		i++;
	}
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	down(t_mlx *e)
{
	int i;
	int j;

	mlx_clear_window(e->mlx, e->win);
	i = 0;
	e->cam.y += MOVEC;
	while (i < e->c.lines)
	{
		j = 0;
		while (j < e->c.points)
		{
			e->mas[i][j].y += MOVEC;
			j++;
		}
		i++;
	}
	drawlines(e->mas, e, e->c);
	legend(e);
}
