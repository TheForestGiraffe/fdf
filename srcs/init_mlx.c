/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:41:14 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 17:46:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

// mlx_destroy_display is only compatible with Linux/X11

void init_mlx(t_app *app)
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
