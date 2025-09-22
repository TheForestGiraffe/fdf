/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 14:01:30 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"
#include "mlx.h"

void	render_img(t_app *app)
{
	erase_img(&app->img, &app->view);
	apply_rotation_to_model(app);
	apply_isometric_projection_to_model(app);
	apply_zoom_to_projection(app);
	apply_translation_to_projection(app);
	render_all_edges(app);
	mlx_put_image_to_window(app->mlx, app->window, app->img.img, 0, 0);
}
