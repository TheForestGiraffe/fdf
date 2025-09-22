/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 07:03:26 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_handling_internal.h"
#include "mlx.h"
#include <stdlib.h>

int	handle_close(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	free_models(app->model, app->projection);
	if (app->img.img)
		mlx_destroy_image(app->mlx, app->img.img);
	if (app->window)
		mlx_destroy_window(app->mlx, app->window);
	if (app->mlx)
		mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
