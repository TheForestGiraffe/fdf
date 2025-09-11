/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/11 19:51:25 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "fdf.h"
#include "libft.h"

static void	parse_map_dimensions(t_map *map, int fd);
static void	init_map_vertices(t_map *map);
static void parse_map(t_map *map, int fd);

t_map	*load_map(char *filepath)
{
	int		fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
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
	close(fd);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("load_map");
		free(map);
		exit(EXIT_FAILURE);
	}
	init_map_vertices(map);
	parse_map(map, fd);
	close(fd);
	return (map);
}

static void	init_map_vertices(t_map *map)
{
	int	y;
	
	map->vertices = (t_vertex **)malloc(map->nr_rows * sizeof(t_vertex *));
	if (!map->vertices)
	{
		free(map);
		ft_putstr_fd("init_map_vertices: failed to initialize map->vertices", 2);
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < map->nr_rows)
	{
		map->vertices[y] = (t_vertex *)malloc(map->nr_columns * sizeof(t_vertex));
		if (!map->vertices[y])
		{
			while (y > 0)
				free(map->vertices[--y]);
			free(map->vertices);
			free(map);
			ft_putstr_fd("init_map_vertices: failed to initialize map->vertice[y]", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

static void	parse_map_dimensions(t_map *map, int fd)
{
	char	*line;
	char	**columns;
	int		x;

	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	columns = ft_split(line, ' ');
	if (!columns)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	x = 0;	
	while (columns[x])
	{
		if (columns[x][0] == '\n')
			break ;
		x++;
	}
	map->nr_columns = x;
	x = 0;
	while (columns[x])
		free(columns[x++]);
	free(columns);
	map->nr_rows = 0;
	while (line)
	{
		if (line[0] == '\n')
			break ;
		map->nr_rows++;
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("cols: %i\n", map->nr_columns);
	ft_printf("rows: %i\n", map->nr_rows);
}

// Convention adopted in parse_map: y = row, x = column

static void	parse_map(t_map *map, int fd)
{
	char	*line;
	char	**columns;
	int		x;
	int		y;

	line = get_next_line(fd);
	ft_printf("line: %s\n", line); //TODO
	y = 0;
	while (line)
	{
		columns = ft_split(line, ' ');
		free(line);
		if (!columns)
			exit(EXIT_FAILURE);
		x = 0;
		while (x < map->nr_columns)
		{
			map->vertices[y][x].x = x;
			map->vertices[y][x].y = y;
			map->vertices[y][x].z = ft_atoi(columns[x]);
			x++;
		}
		x = 0;
		while (x < map->nr_columns)
			free(columns[x++]);
		free(columns);
		line = get_next_line(fd);
		y++;
	}
}
