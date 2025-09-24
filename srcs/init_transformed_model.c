/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transformed_model.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:30:29 by plima             #+#    #+#             */
/*   Updated: 2025/09/24 00:00:33 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_map.h"
#include "fdf.h"
#include <stdlib.h>

static int     init_transformed_model_vertices(t_model *transformed_model, 
    t_app *app);

static t_model	*init_transformed_model(t_app *app)
{
	t_model	*transformed_model;

	transformed_model = (t_model *)malloc(sizeof(t_model));
	if (!transformed_model)
	{
		free_model_vertices(app->model);
        free(app->model);
		perror("init_transformed_model: malloc failed");
		exit(EXIT_FAILURE);
	}
	transformed_model->rows = 0;
	transformed_model->columns = 0;
	if (init_transformed_model_vertices(&transformed_model, app))
	{
		perror("init_transformed_model_vertices: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (transformed_model);
}

static int     init_transformed_model_vertices(t_model *transformed_model, 
    t_app *app)
{
	int	y;

	transformed_model->vertices = malloc(transformed_model->rows * 
        sizeof(t_3d_vertex *));
	if (!transformed_model->vertices)
	{
        free_model_vertices(app->model);
        free(app->model);
		free(transformed_model);
		return (1);
	}
	y = 0;
	while (y < transformed_model->rows)
	{
		transformed_model->vertices[y] = malloc(transformed_model->columns * 
            sizeof(t_3d_vertex));
		if (!transformed_model->vertices[y])
		{
			while (y > 0)
				free(transformed_model->vertices[--y]);
			free(transformed_model);
            free(app->model->vertices);
			free(app->model);
			return (1);
		}
		y++;
	}
}
