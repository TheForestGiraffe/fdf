/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_model_vertices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:23:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"

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
