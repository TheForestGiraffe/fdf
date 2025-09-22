/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_models.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:23 by plima             #+#    #+#             */
/*   Updated: 2025/09/20 21:54:48 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "load_map.h"

static void	free_projection_vertices(t_projection *projection);

// Frees all fully initialized maps

void	free_models(t_model *model, t_projection *projection)
{
	free_model_vertices(model);
	free(model);
	model = NULL;
	free_projection_vertices(projection);
	free(projection);
	projection = NULL;
}

static void	free_projection_vertices(t_projection *projection)
{
	int	y;

	y = projection->rows;
	if (projection->vertices)
	{
		while (y > 0)
		{
			free(projection->vertices[--y]);
			projection->vertices[y] = NULL;
		}
		free(projection->vertices);
		projection->vertices = NULL;
	}
}
