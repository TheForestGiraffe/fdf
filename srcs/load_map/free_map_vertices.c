/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_vertices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:40:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"

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
