/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 15:28:37 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_fdf_internal.h"

void draw_vertices(t_app *app)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	dx = (app->width  - (app->proj_map->nr_columns * app->zoom)) / 2;
	dy = (app->height - (app->proj_map->nr_rows * app->zoom)) / 2;
	app->shift_x = dx;
	app->shift_y = dy;
	i = 0;
	while (i < app->proj_map->nr_rows)
	{
		j = 0;
		while (j < app->proj_map->nr_columns)
		{
			put_pixel(app,
					  (int)(app->proj_map->proj_vertices[i][j].x * app->zoom + dx),
					  (int)(app->proj_map->proj_vertices[i][j].y * app->zoom + dy),
					  app->proj_map->proj_vertices[i][j].color);
			j++;
		}
		i++;
	}
}