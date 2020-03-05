/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:52:30 by asirenko          #+#    #+#             */
/*   Updated: 2019/01/03 15:52:32 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nofile(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	read(fd, "", 0);
	if (errno == 21)
	{
		write(2, filename, ft_strlen(filename));
		write(2, " is a directory\n", 16);
		return (0);
	}
	if (fd == -1)
	{
		write(2, filename, ft_strlen(filename));
		write(2, " not found\n", 11);
		return (0);
	}
	return (1);
}

int		checklines(char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;
	int		z;

	z = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		lines = ft_strsplit(line, ' ');
		while (lines[i])
			free(lines[i++]);
		free(lines);
		free(line);
		if (z == 0)
			z = i;
		if (z != i)
			return (0);
	}
	free(line);
	return (1);
}

int		checkdata(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		k;

	k = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] >= 33 && line[i] <= 126)
			k++;
		i++;
	}
	free(line);
	if (k == 0)
	{
		write(2, "No data found\n", 14);
		return (0);
	}
	return (1);
}

int		validate(char *filename)
{
	if (!nofile(filename))
		return (0);
	if (!checklines(filename))
	{
		write(2, "Wrong lines length\n", 19);
		return (0);
	}
	if (!checkdata(filename))
		return (0);
	return (1);
}
