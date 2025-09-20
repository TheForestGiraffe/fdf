/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:48:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"

void	draw_vertices(t_app *app)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	dx = (app->width - (app->projection->columns * app->zoom)) / 2;
	dy = (app->height - (app->projection->rows * app->zoom)) / 2;
	app->shift_x = dx;
	app->shift_y = dy;
	i = 0;
	while (i < app->projection->rows)
	{
		j = 0;
		while (j < app->projection->columns)
		{
			put_pixel(app,
					  (int)(app->projection->vertices[i][j].x * app->zoom + dx),
					  (int)(app->projection->vertices[i][j].y * app->zoom + dy), 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
