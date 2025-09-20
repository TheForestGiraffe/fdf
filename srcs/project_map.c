/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:21:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "load_map.h"
#include "fdf.h"

// Separate into initialize projected model and compute projection

static t_proj_map	*try_init_proj_map(t_model *model);
static void			try_init_proj_map_vertices(t_model *model, t_proj_map *proj_map);
static void			fill_proj_map(t_model *model, t_proj_map *proj_map);

t_proj_map	*project_map(t_model *model)
{
	t_proj_map	*proj_map;

	proj_map = try_init_proj_map(model);
	try_init_proj_map_vertices(model, proj_map);
	fill_proj_map(model, proj_map);
	return (proj_map);
}

static t_proj_map	*try_init_proj_map(t_model *model)
{
	t_proj_map	*proj_map;

	proj_map = (t_proj_map *)malloc(sizeof(t_proj_map));
	if (!proj_map)
	{
		free_models(model, proj_map);
		ft_putstr_fd("try_init_projected_map: failed to allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	proj_map->nr_rows = model->rows;
	proj_map->nr_columns = model->columns;
	proj_map->proj_vertices = NULL;
	return (proj_map);
}

static void	try_init_proj_map_vertices(t_model *model, t_proj_map *proj_map)
{
	int	y;
	int	size;	

	size = proj_map->nr_rows * sizeof(t_proj_vertex *);
	proj_map->proj_vertices = (t_proj_vertex **)malloc(size);
	if (!proj_map->proj_vertices)
	{
		free_models(model, proj_map);
		ft_putstr_fd("init_proj_map_vertices: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	size = proj_map->nr_columns * sizeof(t_proj_vertex);
	y = 0;
	while (y < proj_map->nr_rows)
	{
		proj_map->proj_vertices[y] = (t_proj_vertex *)malloc(size);
		if (!proj_map->proj_vertices[y])
		{
			while (y > 0)
				free(proj_map->proj_vertices[--y]);
			free(proj_map->proj_vertices);
			proj_map->proj_vertices = NULL;
			free_models(model, proj_map);
			ft_putstr_fd("try_init_proj_map_vertices: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

// Convention adopted in parse_map: y = row, x = column

static void	fill_proj_map(t_model *model, t_proj_map *proj_map)
{
	int		x;
	int		y;
	float	z_scale;

	y = 0;
	z_scale = 0.1;
	while (y < proj_map->nr_rows)
	{
		x = 0;
		while (x < proj_map->nr_columns)
		{
			proj_map->proj_vertices[y][x].x = (x - y) * cos(M_PI / 6);
			proj_map->proj_vertices[y][x].y = (x + y) * sin(M_PI / 6) - (model->vertices[y][x].z * z_scale);
			proj_map->proj_vertices[y][x].color = 0x00FFFFFF;
			x++;
		}
		y++;
	}
}
