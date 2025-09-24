/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_model_vertices.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:24:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "load_map.h"

void	alloc_model_vertices(t_model *model, t_app *app)
{
	int	y;

	model->vertices = malloc(model->rows * sizeof(t_3d_vertex *));
	if (!model->vertices)
	{
		ft_putstr_fd("alloc_model_vertices: 1st malloc failed.\n", 2);
		destroy_app(app, EXIT_FAILURE);
	}
	y = 0;
	while (y < model->rows)
	{
		model->vertices[y] = malloc(model->columns * sizeof(t_3d_vertex));
		if (!model->vertices[y])
		{
			while (y > 0)
				free(model->vertices[--y]);
			ft_putstr_fd("alloc_model_vertices: 2nd malloc failed.\n", 2);
			destroy_app(app, EXIT_FAILURE);
		}
		y++;
	}
}
