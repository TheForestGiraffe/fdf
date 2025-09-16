/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 17:59:15 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
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
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;
	
	i = 0;
	while (i < proj_map->nr_rows)
	{
		j = 0;
		while (j < proj_map->nr_columns)
		{
			x = map->vertices[i][j].x;
			y = map->vertices[i][j].y;
			z = map->vertices[i][j].z;
			proj_map->proj_vertices[i][j].x = (x - y) * cos(M_PI/6);
			proj_map->proj_vertices[i][j].y = (x + y) * sin(M_PI/6) - z;
			proj_map->proj_vertices[i][j].color = 0x00FFFFFF;
			j++;
		}
		i++;
	}
}
