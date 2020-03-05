/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:12:09 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/13 18:46:59 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*e;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf map_file");
		exit(0);
	}
	if (!validate(argv[1]))
		exit(0);
	e = (t_mlx *)malloc(sizeof(t_mlx));
	e->mas = read_file(argv[1]);
	e->c = count_lp(argv[1]);
	changecolour(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, SCREEN_W, SCREEN_H, "fdf");
	change_m(e);
	flat_dots(e);
	center_dots(e);
	draw_points(e->mas, e, e->c);
	drawlines(e->mas, e, e->c);
	legend(e);
	mlx_hook(e->win, 2, 1L << 2, rotate, e);
	mlx_key_hook(e->win, deal_key, e);
	mlx_hook(e->win, 17, 1L << 17, exit_x, (void *)0);
	mlx_loop(e->mlx);
}
