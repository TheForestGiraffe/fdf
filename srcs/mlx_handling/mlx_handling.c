/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 18:15:15 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include <stdlib.h>
#include <X11/keysym.h>

void	init_mlx(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		free_maps(app->map, app->proj_map);
		exit(EXIT_FAILURE);
	}
	app->width = 800;
	app->height = 600;
	app->window = mlx_new_window(app->mlx, app->width, app->height, "FDF");
	if (!app->window)
	{
		free_maps(app->map, app->proj_map);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		exit(EXIT_FAILURE);
	}	
}

void	setup_mlx_hooks(t_app *app)
{
	mlx_hook(app->window, ON_DESTROY, 0, &handle_close, app);
	mlx_hook(app->window, ON_KEYDOWN, KEY_PRESS_MASK, &handle_keydown, app);
}

void	init_mlx_img(t_app *app)
{
	app->img = mlx_new_image(app->mlx, app->width, app->height);
	app->img_address = mlx_get_data_addr(app->img, &app->bits_per_pixel, 
										&app->size_line, &app->endian);
}
