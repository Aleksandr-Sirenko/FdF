/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:24:36 by asirenko          #+#    #+#             */
/*   Updated: 2018/12/14 20:25:55 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_dots(char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		lines = ft_strsplit(line, ' ');
		free(line);
		while (lines[i])
		{
			count++;
			free(lines[i]);
			i++;
		}
		free(lines);
	}
	free(line);
	return (count);
}

int			count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	free(line);
	return (count);
}

int			count_points(char *filename)
{
	int		fd;
	char	*line;
	int		count;
	int		i;
	char	**lines;

	i = 0;
	count = 0;
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	lines = ft_strsplit(line, ' ');
	free(line);
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (i);
}

t_count		count_lp(char *filename)
{
	t_count count;

	count.lines = count_lines(filename);
	count.points = count_points(filename);
	count.dots = count_dots(filename);
	return (count);
}
