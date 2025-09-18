/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:23 by plima             #+#    #+#             */
/*   Updated: 2025/09/18 10:56:48 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "load_map.h"

static void free_proj_map_vertices(t_proj_map *proj_map);

// Frees all fully initialized maps

void    free_maps(t_map *map, t_proj_map *proj_map)
{
    free_map_vertices(map);
    free(map);
    map = NULL;
    free_proj_map_vertices(proj_map);
    free(proj_map);
    proj_map = NULL;
}

static void	free_proj_map_vertices(t_proj_map *proj_map)
{
	int	y;

	y = proj_map->nr_rows;
	if (proj_map->proj_vertices)
	{
		while (y > 0)
		{
			free(proj_map->proj_vertices[--y]);
			proj_map->proj_vertices[y] = NULL;
		}
		free(proj_map->proj_vertices);
		proj_map->proj_vertices = NULL;
	}
}