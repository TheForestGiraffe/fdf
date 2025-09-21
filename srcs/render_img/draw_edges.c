/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:58:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:29:07 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h> // abs()
#include "fdf.h"
#include "render_img_internal.h"
#include "mlx.h"

void	draw_edge(t_app *app);
void	draw(t_app *app, int dx, int dy, int decision);
int		calc_direction(int start, int end);

void	draw_edges(t_app *app)
{
	int	y;
	int	x;

	y = 0;
	while ((y < app->projection->rows))
	{
		x = 0;
		while ((x < app->projection->columns))
		{
			app->edge.x0 = (int)round(app->projection->vertices[y][x].x);
			app->edge.y0 = (int)round(app->projection->vertices[y][x].y);
			if (x < app->projection->columns - 1)
			{
				app->edge.x1 = (int)round(app->projection->vertices[y][x + 1].x);
				app->edge.y1 = (int)round(app->projection->vertices[y][x + 1].y);
				draw_edge(app);
				mlx_put_image_to_window(app->mlx, app->window, app->img.img, 0, 0);
			}
			app->edge.x0 = (int)round(app->projection->vertices[y][x].x);
			app->edge.y0 = (int)round(app->projection->vertices[y][x].y);
			if (y < app->projection->rows - 1)
			{
				app->edge.x1 = (int)round(app->projection->vertices[y + 1][x].x);
				app->edge.y1 = (int)round(app->projection->vertices[y + 1][x].y);
				draw_edge(app);
				mlx_put_image_to_window(app->mlx, app->window, app->img.img, 0, 0);
			}
			x++;
		}
		y++;
	}
}

void	draw_edge(t_app *app)
{
	int	dx;
	int	dy;
	int	decision;

	dx = abs(app->edge.x1 - app->edge.x0);
	dy = abs(app->edge.y1 - app->edge.y0);
	decision = dx - dy;
	draw(app, dx, dy, decision);
}

void	draw(t_app *app, int dx, int dy, int decision)
{
	int	direction_x;
	int	direction_y;
	int	decision_2;

	direction_x = calc_direction(app->edge.x0, app->edge.x1);
	direction_y = calc_direction(app->edge.y0, app->edge.y1);
	while (1)
	{
		put_pixel(app->edge.x0, app->edge.y0, &app->view, &app->img);
		if (app->edge.x0 == app->edge.x1 && app->edge.y0 == app->edge.y1)
			break ;
		decision_2 = 2 * decision;
		if (decision_2 > -dy)
		{
			decision -= dy;
			app->edge.x0 += direction_x;
		}
		if (decision_2 < dx)
		{
			decision += dx;
			app->edge.y0 += direction_y;
		}
	}
}

int	calc_direction(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}
