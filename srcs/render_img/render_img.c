/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:37:43 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"
#include "mlx.h"

void	render_img(t_app *app)
{
	erase_img(&app->img, &app->view);
	rotate_model(app);
	apply_isometric_projection(app);
	zoom_projection(app);
	centralize_view_once(&app->view, app->projection);
	translate_projection(app);
	render_all_edges(app);
	mlx_put_image_to_window(app->mlx, app->window, app->img.img, 0, 0);
}
