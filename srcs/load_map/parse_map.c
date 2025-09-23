/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/23 17:02:05 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

static void	set_model_xyz(int fd, char *line, t_model *model);

// Convention adopted: y = row, x = column

void	parse_map(t_model *model, char *filepath)
{
	int		fd;
	char	*line;

	fd = try_open(filepath, model);
	line = try_get_next_line(fd, model);
	set_model_xyz(fd, line, model);
}

static void	set_model_xyz(int fd, char *line, t_model *model)
{
	int		x;
	int		y;
	char	**split_line;

	y = 0;
	while (line)
	{
		split_line = try_ft_split(line, model);
		free(line);
		x = 0;
		while (x < model->columns)
		{
			model->vertices[y][x].x = x;
			model->vertices[y][x].y = y;
			model->vertices[y][x].z = ft_atoi(split_line[x]);
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
