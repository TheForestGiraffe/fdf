/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:20:08 by pecavalc         ###   ########.fr       */
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
	free_models(app->model, app->proj_map);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
