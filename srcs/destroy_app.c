/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_app.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 12:36:56 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "load_map.h"

void	destroy_app(t_app *app, int exit_code)
{
	if (!app->model)
		free_model(app); // TOOD: implementar free_model incl. vertices






	free_model_vertices(model);
	free(model);
	model = NULL;
	free_projection_vertices(projection);
	free(projection);
	projection = NULL;
}



void	free_model_vertices(t_model *model)
{
	int	y;

	y = model->rows;
	if (model->vertices)
	{
		while (y > 0)
		{
			free(model->vertices[--y]);
			model->vertices[y] = NULL;
		}
		free(model->vertices);
		model->vertices = NULL;
	}
}
