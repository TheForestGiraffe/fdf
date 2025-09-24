/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:30:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "load_map.h"
#include "load_map_internal.h"

static void	set_model_xyz(int fd, char *line, t_app *app);

// Convention adopted: y = row, x = column

void	parse_map(char *filepath, t_app *app)
{
	int		fd;
	char	*line;

	fd = try_open(filepath, app);
	line = try_get_next_line(fd, app);
	set_model_xyz(fd, line, app);
}

static void	set_model_xyz(int fd, char *line, t_app *app)
{
	int		x;
	int		y;
	char	**split_line;

	y = 0;
	while (line)
	{
		split_line = try_ft_split(line, app);
		free(line);
		x = 0;
		while (x < app->model->columns)
		{
			app->model->vertices[y][x].x = x;
			app->model->vertices[y][x].y = y;
			app->model->vertices[y][x].z = ft_atoi(split_line[x]);
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
