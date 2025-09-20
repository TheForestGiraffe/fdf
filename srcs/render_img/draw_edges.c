/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:58:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 19:34:18 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> // round()
#include <stdlib.h> // abs()
#include "fdf.h"
#include "render_img_internal.h"
#include "libft.h"
#include "mlx.h"

void	draw_single_edge(t_app *app, int x_start, int y_start, int x_end, int y_end, int color);

void	draw_all_edges(t_app *app)
{
	int	x;
	int y;

	y = 0;
	while ((y <  app->proj_map->nr_rows))
	{
		x = 0;
		while ((x < app->proj_map->nr_columns))
		{	
			// Line to right neighboor
			if (x < app->proj_map->nr_columns - 1)
				draw_single_edge(app, x, y, x + 1, y, app->proj_map->proj_vertices[y][x].color);
            	
			// Line to bottom neighbor
			if (y < app->proj_map->nr_rows - 1)
            	draw_single_edge(app, x, y, x, y + 1, app->proj_map->proj_vertices[y][x].color);
			x++;
		}
		y++;
	}
}

void	draw_single_edge(t_app *app, int x_start, int y_start, int x_end, int y_end, int color)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int dx;
	int dy;
	int direction_x;
	int direction_y;
	int decision;
	int	decision_2;

	x0 = (int)round(app->proj_map->proj_vertices[y_start][x_start].x * app->zoom + app->shift_x);
	y0 = (int)round(app->proj_map->proj_vertices[y_start][x_start].y * app->zoom + app->shift_y);
	x1 = (int)round(app->proj_map->proj_vertices[y_end][x_end].x * app->zoom + app->shift_x);
	y1 = (int)round(app->proj_map->proj_vertices[y_end][x_end].y * app->zoom + app->shift_y);
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		direction_x = 1;
	else
		direction_x = -1;
	if (y0 < y1)
		direction_y = 1;
	else
		direction_y = -1;
	decision = dx - dy;
	while(1)
	{
		put_pixel(app, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		decision_2 = 2 * decision;
		if (decision_2 > -dy)
		{
			decision -= dy;
			x0 += direction_x;
		}
		if (decision_2 < dx)
		{
			decision += dx;
			y0 += direction_y;
		}
	}
}