/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 02:27:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fdf_map.h"
#include "fdf_map_internal.h"

static void		count_and_set_nr_columns(char **split_line, t_map *map);
static void		count_and_set_nr_rows(char *line, int fd, t_map *map);

void	parse_map_dimensions(t_map *map, char *filepath)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = try_open(filepath, map);
	line = try_get_next_line(fd, map);
	split_line = try_ft_split(line, map);
	count_and_set_nr_columns(split_line, map);
	count_and_set_nr_rows(line, fd, map);
	close(fd);
}

static void	count_and_set_nr_columns(char **split_line, t_map *map)
{
	int	i;

	i = 0;
	
	while (split_line[i])
	{
		if (split_line[i][0] == '\n')
			break ;
		i++;
	}
	map->nr_columns = i;
	i = 0;
	while (split_line[i])
		free(split_line[i++]);
	free(split_line);
}

static void count_and_set_nr_rows(char *line, int fd, t_map *map)
{
	while (line)
	{
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			break ;
		}
		map->nr_rows++;
		free(line);
		line = get_next_line(fd);
	}
}
