/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:44:52 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:50:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_projection *alloc_projection(t_app *app)
{
	t_projection	*projection;

	projection = (t_projection *)malloc(sizeof(t_projection));
	if (!projection)
	{
		perror("alloc_projection: malloc failed");
		destroy_app(app, EXIT_FAILURE);
	}
	projection->rows = model->rows;
	projection->columns = model->columns;
	if (init_projection_vertices(model, projection))
	{
		perror("init_projection_vertices: malloc failed");
		exit(EXIT_FAILURE);
	}
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
