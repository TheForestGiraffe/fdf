/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:58:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:02:13 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // abs()
#include "fdf.h"
#include "render_img_internal.h"

void	draw_edge(t_app *app);
void	draw(t_app *app, int dx, int dy, int decision);
int		calc_direction(int start, int end);

void	draw_edges(t_app *app)
{
	app->edge.y0 = 0;
	while ((app->edge.y0 < app->projection->rows))
	{
		app->edge.x0 = 0;
		while ((app->edge.x0 < app->projection->columns))
		{
			if (app->edge.x0 < app->projection->columns - 1)
			{
				app->edge.x1 = app->edge.x0 + 1;
				app->edge.y1 = app->edge.y0;
				draw_edge(app);
			}
			if (app->edge.y0 < app->projection->rows - 1)
			{
				app->edge.x1 = app->edge.x0;
				app->edge.y1 = app->edge.y0 + 1;
				draw_edge(app);
			}
			app->edge.x0++;
		}
		app->edge.y0++;
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
