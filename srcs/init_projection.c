/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:17:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "load_map.h"
#include "fdf.h"

static int	init_projection_vertices(t_model *model, t_projection *projection);

t_projection	*init_projection(t_model *model)
{
	t_projection	*projection;

	projection = (t_projection *)malloc(sizeof(t_projection));
	if (!projection)
	{
		free_models(model, projection);
		perror("init_projection: malloc failed");
		exit(EXIT_FAILURE);
	}
	projection->rows = model->rows;
	projection->columns = model->columns;
	if (init_projection_vertices(model, projection))
	{
		perror("init_projection_vertices: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (projection);
}

static int	init_projection_vertices(t_model *model, t_projection *projection)
{
	int	y;

	projection->vertices = malloc(projection->rows * sizeof(t_2d_vertex *));
	if (!projection->vertices)
	{
		free_models(model, projection);
		return (1);
	}
	y = 0;
	while (y < projection->rows)
	{
		projection->vertices[y] = 
			malloc(projection->columns * sizeof(t_2d_vertex));
		if (!projection->vertices[y])
		{
			while (y > 0)
				free(projection->vertices[--y]);
			free(projection->vertices);
			projection->vertices = NULL;
			free_models(model, projection);
			return (1);
		}
		y++;
	}
	return (0);
}
