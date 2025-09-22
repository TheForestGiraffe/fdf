/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zoom_to_projection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:29:45 by plima             #+#    #+#             */
/*   Updated: 2025/09/22 13:22:39 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_handling_internal.h"
#include "render_img.h"

void    apply_zoom_to_projection(t_app *app)
{
    int		x;
	int		y;

	y = 0;
	while (y < app->projection->rows)
	{
		x = 0;
		while (x < app->projection->columns)
		{
			app->projection->vertices[y][x].x *= app->view.zoom;
			app->projection->vertices[y][x].y *= app->view.zoom;
			x++;
		}
		y++;
	}
}
