/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:21:57 by pecavalc         ###   ########.fr       */
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
		free_models(app->model, app->proj_map);
		exit(EXIT_FAILURE);
	}
	app->width = 800;
	app->height = 600;
	app->window = mlx_new_window(app->mlx, app->width, app->height, "FDF");
	if (!app->window)
	{
		free_models(app->model, app->proj_map);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		exit(EXIT_FAILURE);
	}
}
