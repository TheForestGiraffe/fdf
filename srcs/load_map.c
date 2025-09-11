/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/11 13:00:06 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "fdf.h"
#include "libft.h"

static void	parse_map_dimensions(t_map *map, int fd);
static void parse_map(t_map *map, int fd);

t_map	*load_map(char *filepath)
{
	int		fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(map));
	if (!map)
	{
		ft_putstr_fd("load_map: failed to allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("load_map");
		free(map);
		exit(EXIT_FAILURE);
	}
	parse_map_dimensions(map, fd);
	parse_map(map, fd);
	close(fd);
	return (map);
}

static void	parse_map_dimensions(t_map *map, int fd)
{
	char	*line;
	char	**rows;
	int		x;

	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	rows = ft_split(line, ' ');
	if (!rows)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	x = 0;	
	while (rows[x])
		x++;
	map->nr_columns = x;
	x = 0;
	while (rows[x])
		free(rows[x++]);
	free(rows);
	map->nr_rows = 0;
	while (line)
	{
		map->nr_rows++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	parse_map(t_map *map, int fd)
{
	char	*line;
	char	**rows;
	int		x;
	int		y;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		rows = ft_split(line, ' ');
		free(line);
		if (!rows)
			exit(EXIT_FAILURE);
		x = 0;
		while (rows[x])
		{
			map->vertices[x][y].x = x;
			map->vertices[x][y].y = y;
			map->vertices[x][y].z = ft_atoi(rows[x]);
			x++;
		}
		x = 0;
		while (rows[x])
			free(rows[x++]);
		free(rows);
		line = get_next_line(fd);
		y++;
	}
}
