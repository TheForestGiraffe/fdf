/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometric_projection_to_model.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 13:19:22 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "load_map.h"
#include "fdf.h"

void	apply_isometric_projection_to_model(t_app *app)
{
	int		x;
	int		y;

	y = 0;
	while (y < app->projection->rows)
	{
		x = 0;
		while (x < app->projection->columns)
		{
			app->projection->vertices[y][x].x = (x - y) * cos(M_PI / 6);
			app->projection->vertices[y][x].y = (x + y) * sin(M_PI / 6) - 
				(app->model->vertices[y][x].z * app->view.scale_z);
			x++;
		}
		y++;
	}
}
