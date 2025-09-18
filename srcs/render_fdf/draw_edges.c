/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:58:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 15:31:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> // fabs()
#include "fdf.h"
#include "render_fdf_internal.h"
#include "libft.h"
#include "mlx.h"

static void	draw_hor_edge(t_app *app, int x, int y);
static void	draw_ver_edge(t_app *app, int x, int y);
static void	draw_hor_edge_to_bottom(t_app *app, int x, int y);
static void	draw_ver_edge_to_bottom(t_app *app, int x, int y);

void	draw_edges(t_app *app)
{
	int	x;
	int y;
	double	x0;
	double	x1;
	double	y0;
	double	y1;

	y = 0;
	while ((y <  app->proj_map->nr_rows))
	{
		// Draw right neighboor
		x = 0;
		while ((x < app->proj_map->nr_columns))
		{	
			// Draw right neightboor
			if (x != app->proj_map->nr_columns - 1)
			{
				x0 = app->proj_map->proj_vertices[y][x].x * app->zoom;
				y0 = app->proj_map->proj_vertices[y][x].y * app->zoom;
				x1 = app->proj_map->proj_vertices[y][x + 1].x * app->zoom;
				y1 = app->proj_map->proj_vertices[y][x + 1].y * app->zoom;
				if (x < app->proj_map->nr_columns - 1)
				{
					if (fabs(x1 - x0) > fabs(y1 - y0))
								draw_hor_edge(app, x, y);
					else
								draw_ver_edge(app, x, y);
				}
			}
			// Draw bottom neighboor
			if (y != app->proj_map->nr_rows - 1)
			{
				x0 = app->proj_map->proj_vertices[y][x].x * app->zoom;
				y0 = app->proj_map->proj_vertices[y][x].y * app->zoom;
				x1 = app->proj_map->proj_vertices[y + 1][x].x * app->zoom;
				y1 = app->proj_map->proj_vertices[y + 1][x].y * app->zoom;
				if (y < app->proj_map->nr_rows - 1)
				{
					if (fabs(x1 - x0) > fabs(y1 - y0))
						draw_hor_edge_to_bottom(app, x, y);
					else
						draw_ver_edge_to_bottom(app, x, y);
				}
			}
			x++;
			mlx_put_image_to_window(app->mlx, app->window, app->img, 0, 0);
		}
		y++;
	}
}

static void	draw_hor_edge(t_app *app, int x, int y)
{
	int	x0;
	int	x1;
	int y0;
	int y1;
	int dx;
	int dy;
	int direction;
	int	decision_param;
	int	i;

	x0 = app->proj_map->proj_vertices[y][x].x * app->zoom + app->shift_x;
	y0 = app->proj_map->proj_vertices[y][x].y * app->zoom + app->shift_y;
	x1 = app->proj_map->proj_vertices[y][x+1].x * app->zoom + app->shift_x;
	y1 = app->proj_map->proj_vertices[y][x+1].y * app->zoom + app->shift_y;

	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if  (dy < 0)
		direction = -1;
	else
		direction = 1;
	dy *= direction;
	if (dx != 0)
	{
		decision_param = 2*dy - dx;
		i = 0;
		while (i < (dx + 1))
		{
			put_pixel(app, x0 + i, y0, app->proj_map->proj_vertices[y][x].color);
			if (decision_param >= 0)
			{
				y0 += direction;
				decision_param = decision_param - (2 * dx);
			}
			decision_param = decision_param + (2 * dy);
			i++;
		}
	}
}

static void	draw_ver_edge(t_app *app, int x, int y)
{
int	x0;
	int	x1;
	int y0;
	int y1;
	int dx;
	int dy;
	int direction;
	int	decision_param;
	int	i;

	x0 = app->proj_map->proj_vertices[y][x].x * app->zoom + app->shift_x;
	y0 = app->proj_map->proj_vertices[y][x].y * app->zoom + app->shift_y;
	x1 = app->proj_map->proj_vertices[y+1][x].x * app->zoom + app->shift_x;
	y1 = app->proj_map->proj_vertices[y+1][x].y * app->zoom + app->shift_y;

	if (y0 > y1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if  (dx < 0)
		direction = -1;
	else
		direction = 1;
	dx *= direction;
	if (dy != 0)
	{
		decision_param = 2*dy - dx;
		i = 0;
		while (i < (dy + 1))
		{
			put_pixel(app, x0, y0 + i, app->proj_map->proj_vertices[y][x].color);
			if (decision_param >= 0)
			{
				x0 += direction;
				decision_param = decision_param - (2 * dy);
			}
			decision_param = decision_param + (2 * dx);
			i++;
		}
	}
}

static void	draw_hor_edge_to_bottom(t_app *app, int x, int y)
{
	int	x0;
	int	x1;
	int y0;
	int y1;
	int dx;
	int dy;
	int direction;
	int	decision_param;
	int	i;

	x0 = app->proj_map->proj_vertices[y][x].x * app->zoom + app->shift_x;
	y0 = app->proj_map->proj_vertices[y][x].y * app->zoom + app->shift_y;
	x1 = app->proj_map->proj_vertices[y + 1][x].x * app->zoom + app->shift_x;
	y1 = app->proj_map->proj_vertices[y + 1][x].y * app->zoom + app->shift_y;

	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
		direction = -1;
	else
		direction = 1;
	dy *= direction;
	if (dx != 0)
	{
		decision_param = 2 * dy - dx;
		i = 0;
		while (i <= dx + 1)
		{
			put_pixel(app, x0 + i, y0, app->proj_map->proj_vertices[y][x].color);
			if (decision_param >= 0)
			{
				y0 += direction;
				decision_param -= 2 * dx;
			}
			decision_param += 2 * dy;
			i++;
		}
	}
}

static void	draw_ver_edge_to_bottom(t_app *app, int x, int y)
{
	int	x0;
	int	x1;
	int y0;
	int y1;
	int dx;
	int dy;
	int direction;
	int	decision_param;
	int	i;

	x0 = app->proj_map->proj_vertices[y][x].x * app->zoom + app->shift_x;
	y0 = app->proj_map->proj_vertices[y][x].y * app->zoom + app->shift_y;
	x1 = app->proj_map->proj_vertices[y + 1][x].x * app->zoom + app->shift_x;
	y1 = app->proj_map->proj_vertices[y + 1][x].y * app->zoom + app->shift_y;

	if (y0 > y1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
		direction = -1;
	else
		direction = 1;
	dx *= direction;
	if (dy != 0)
	{
		decision_param = 2 * dy - dx;
		i = 0;
		while (i <= dy + 1)
		{
			put_pixel(app, x0, y0 + i, app->proj_map->proj_vertices[y][x].color);
			if (decision_param >= 0)
			{
				x0 += direction;
				decision_param -= 2 * dy;
			}
			decision_param += 2 * dx;
			i++;
		}
	}
}
