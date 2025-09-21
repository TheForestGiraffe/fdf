/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 00:54:36 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	init_mlxwindow(t_app *app)
{
	app->window = mlx_new_window(app->mlx, app->view.width, 
			app->view.height, "FDF");
	if (!app->window)
	{
		free_models(app->model, app->projection);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		exit(EXIT_FAILURE);
	}
}
