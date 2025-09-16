/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 11:56:03 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

static int 	handle_close(void *param);

void	setup_mlx_hooks(t_app *app)
{
	mlx_hook(app->window, 17, 0, &handle_close, app);
}

// mlx_destroy is only compatible with Linux/X11

static int 	handle_close(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	free_maps(app->map, app->proj_map);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}