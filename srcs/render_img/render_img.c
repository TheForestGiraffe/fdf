/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 11:59:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"
#include "mlx.h"

void	render_img(t_app *app)
{
	erase_img(&app->img, &app->view);
	apply_rotation_from_model(app);
	apply_isometric_projection_from_transformed_model(app);
	apply_zoom_to_projection(app);
	if ((app->view.shift_x == 0) && (app->view.shift_y == 0))
		centralize_view(&app->view, app->projection);
	apply_translation_to_projection(app);
	render_all_edges(app);
	mlx_put_image_to_window(app->mlx, app->window, app->img.img, 0, 0);
}
