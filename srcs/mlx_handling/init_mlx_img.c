/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:15:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include <stdlib.h>
#include <X11/keysym.h>

void	init_mlx_img(t_app *app)
{
	app->img = mlx_new_image(app->mlx, app->width, app->height);
	app->img_address = mlx_get_data_addr(app->img, &app->bits_per_pixel, &app->size_line, &app->endian);
}
