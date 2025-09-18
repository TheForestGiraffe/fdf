/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:41:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

static void	set_map_xyz(int fd, char *line, t_map *map);

// Convention adopted in parse_map: y = row, x = column

void	parse_map(t_map *map, char *filepath)
{
	int		fd;
	char	*line;

	fd = try_open(filepath, map);
	line = try_get_next_line(fd, map);
	set_map_xyz(fd, line, map);
}

static void	set_map_xyz(int fd, char *line, t_map *map)
{
	int		x;
	int		y;
	char	**split_line;
	
	y = 0;
	while (line)
	{
		split_line = try_ft_split(line, map);
		free(line);
		x = 0;
		while (x < map->nr_columns)
		{
			map->vertices[y][x].x = x;
			map->vertices[y][x].y = y;
			map->vertices[y][x].z = ft_atoi(split_line[x]);
			x++;
		}
		x = 0;
		while (split_line[x])
			free(split_line[x++]);
		free(split_line);
		line = get_next_line(fd);
		y++;
	}
}
