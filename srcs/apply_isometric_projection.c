/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometric_projection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 04:10:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "load_map.h"
#include "fdf.h"

void	apply_isometric_projection(t_app *app)
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
			app->projection->vertices[y][x].x *= app->view.zoom;
			app->projection->vertices[y][x].x += app->view.shift_x;
			app->projection->vertices[y][x].y = (x + y) * sin(M_PI / 6) - 
				(app->model->vertices[y][x].z * app->view.scale_z);
			app->projection->vertices[y][x].y *= app->view.zoom;
			app->projection->vertices[y][x].y += app->view.shift_y;
			x++;
		}
		y++;
	}
}
