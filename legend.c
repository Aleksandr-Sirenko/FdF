/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:45:20 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/17 21:45:25 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	legend(t_mlx *e)
{
	char *str;

	mlx_string_put(e->mlx, e->win, 20, 20, WH, "Move: W A S D");
	mlx_string_put(e->mlx, e->win, 20, 40, WH, "Zoom-in: +");
	mlx_string_put(e->mlx, e->win, 20, 60, WH, "Zoom-out: -");
	mlx_string_put(e->mlx, e->win, 20, 80, WH, "X-Axis Rotation: X");
	mlx_string_put(e->mlx, e->win, 20, 100, WH, "Y-Axis Rotation: Y");
	mlx_string_put(e->mlx, e->win, 20, 120, WH, "Z-Axis Rotation: Z");
	mlx_string_put(e->mlx, e->win, 20, 140, WH, "Center Camera: Space");
	mlx_string_put(e->mlx, e->win, 20, 160, WH, "Projections: 1 2");
	mlx_string_put(e->mlx, e->win, 20, 180, WH, "Exit: Esc");
	mlx_string_put(e->mlx, e->win, SCREEN_W - 180, 20, WH, "Camera X");
	str = ft_itoa(e->cam.x);
	mlx_string_put(e->mlx, e->win, SCREEN_W - 60, 20, WH, str);
	free(str);
	mlx_string_put(e->mlx, e->win, SCREEN_W - 180, 40, WH, "Camera Y");
	str = ft_itoa(e->cam.y);
	mlx_string_put(e->mlx, e->win, SCREEN_W - 60, 40, WH, str);
	free(str);
	mlx_string_put(e->mlx, e->win, SCREEN_W - 180, 60, WH, "Zoom");
	str = ft_itoa(e->zoom);
	mlx_string_put(e->mlx, e->win, SCREEN_W - 60, 60, WH, str);
	free(str);
}
