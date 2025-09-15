/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_vertices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/15 10:58:59 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_map.h"

void	free_map_vertices(t_map *map)
{
	int	y;

	y = map->nr_rows;
	if (map->vertices)
	{
		while (y > 0)
		{
			free(map->vertices[--y]);
			map->vertices[y] = NULL;
		}
		free(map->vertices);
		map->vertices = NULL;
	}
}
