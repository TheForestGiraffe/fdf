/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_init_map_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 01:07:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_map.h"

void	try_init_map_vertices(t_map *map)
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
