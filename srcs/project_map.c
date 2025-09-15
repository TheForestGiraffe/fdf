/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/15 11:36:44 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_map.h"
#include "fdf.h"

static t_proj_map	*try_init_proj_map(t_map *map);
static void			try_init_proj_map_vertices(t_map *map, t_proj_map *proj_map);
static void			fill_proj_map(t_map *map, t_proj_map *proj_map);

t_proj_map	*project_map(t_map *map)
{
	t_proj_map	*proj_map;

	proj_map = try_init_proj_map(map);
	try_init_proj_map_vertices(map, proj_map);
	fill_proj_map(map, proj_map);

	return (proj_map);
}

static t_proj_map	*try_init_proj_map(t_map *map)
{
	t_proj_map	*proj_map;

	proj_map = (t_proj_map *)malloc(sizeof(t_proj_map));
	if (!proj_map)
	{
		free_maps(map, proj_map);
		ft_putstr_fd("try_init_projected_map: failed to allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	proj_map->nr_rows = map->nr_rows;
	proj_map->nr_columns = map->nr_columns;
	proj_map->proj_vertices = NULL;
	return (proj_map);
}

static void	try_init_proj_map_vertices(t_map *map, t_proj_map *proj_map)
{
	int	y;
	int	size;	

	size = proj_map->nr_rows * sizeof(t_proj_vertex *);
	proj_map->proj_vertices = (t_proj_vertex **)malloc(size);
	if (!proj_map->proj_vertices)
	{
		free_maps(map, proj_map);
		ft_putstr_fd("init_proj_map_vertices: failed to initialize proj_map->vertices", 2);
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
			free_maps(map, proj_map);
			ft_putstr_fd("try_init_proj_map_vertices: failed to initialize proj_map->proj_vertices[y]", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

// Convention adopted in parse_map: y = row, x = column

static void	fill_proj_map(t_map *map, t_proj_map *proj_map)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < proj_map->nr_rows)
	{
		x = 0;
		while (x < proj_map->nr_columns)
		{
			proj_map->proj_vertices[y][x].x = map->vertices[y][x].x; // TODO
			proj_map->proj_vertices[y][x].y = map->vertices[y][x].y; // TODO
			x++;
		}
		y++;
	}
}
