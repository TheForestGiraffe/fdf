/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_proj_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 18:04:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	put_pixel(t_app *app, int x, int y, int color);

void	render_proj_map(t_app *app)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	app->zoom = 20;
	dx = (app->width  - (app->proj_map->nr_columns * app->zoom)) / 2;
	dy = (app->height - (app->proj_map->nr_rows * app->zoom)) / 2;
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
	mlx_put_image_to_window(app->mlx, app->window, app->img, 0, 0);
}

static void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*pixel_address;

	if (x < 0 || x >= app->width || y < 0 || y >= app->height)
		return ;
	pixel_address = app->img_address + (y * app->size_line)
									 + (x * app->bits_per_pixel/8);
	*(unsigned int *)pixel_address = color;
}