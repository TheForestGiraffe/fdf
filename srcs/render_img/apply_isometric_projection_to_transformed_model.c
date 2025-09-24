/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometric_projection_to_transformed_m        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/23 23:25:22 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "load_map.h"
#include "fdf.h"

void	apply_isometric_projection_from_transformed_model(t_app *app)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	j = 0;
	while (j < app->model->rows)
	{
		i = 0;
		while (i < app->model->columns)
		{
			x = app->model->vertices[j][i].x;
			y = app->model->vertices[j][i].y;
			z = app->model->vertices[j][i].z;
			app->transformed_model->vertices[j][i].x = (x - y) * cos(M_PI / 6);
			app->transformed_model->vertices[j][i].y = (x + y) * sin(M_PI / 6) 
				- (z * app->view.scale_z);
			i++;
		}
		j++;
	}
}
