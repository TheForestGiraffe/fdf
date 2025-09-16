/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:25:42 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 16:46:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_mlx_img(t_app *app)
{
	app->img = mlx_new_image(app->mlx, app->width, app->height);
	app->img_address = mlx_get_data_addr(app->img, &app->bits_per_pixel, 
										&app->size_line, &app->endian);
}