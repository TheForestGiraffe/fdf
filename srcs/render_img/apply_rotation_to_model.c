/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation_to_model.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:47:58 by plima             #+#    #+#             */
/*   Updated: 2025/09/23 16:55:18 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    apply_rotation_to_model(t_app *app)
{
    (void)app;
/*
    int		x;
	int		y;

	y = 0;
	while (y < app->model->rows)
	{
		x = 0;
		while (x < app->model->columns)
		{
			app->projection->vertices[y][x].x = app->view.shift_x;
			app->projection->vertices[y][x].y += app->view.shift_y;
			x++;
		}
		y++;
	}
    //TODO:
    // rotate_around_x_axis(...);
    // rotate_around_y_axis(...);
    */
}

/*
void    rotate_around_x(int x, int y, t_app *app)
{
    int z;
    int theta;

    z = app->model->vertices[y][x].z;
    theta = app->view.rot_angle_x;
    app->model->vertices[y][x].y = y * cos(theta) - z * sin(theta);
    app->model ->vertices[y][x].z = y * sin(theta) + z * cos(theta);
}
*/