/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:00:37 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/04 20:01:49 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyplus(t_mlx *e)
{
	mlx_clear_window(e->mlx, e->win);
	mashtab(e);
	center_dots2(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}

void	keyminus(t_mlx *e)
{
	mlx_clear_window(e->mlx, e->win);
	mashtab2(e);
	center_dots2(e);
	drawlines(e->mas, e, e->c);
	legend(e);
}
