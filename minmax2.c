/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:05:24 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/04 20:05:28 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_z(t_point **mas, t_count c)
{
	int i;
	int j;
	int maxz;

	maxz = 0;
	i = 0;
	while (i < c.lines)
	{
		j = 0;
		while (j < c.points)
		{
			if (mas[i][j].z > maxz)
				maxz = mas[i][j].z;
			j++;
		}
		i++;
	}
	return (maxz);
}

int		min_z(t_point **mas, t_count c)
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
			if (mas[i][j].z < maxy)
				maxy = mas[i][j].z;
			j++;
		}
		i++;
	}
	return (maxy);
}
