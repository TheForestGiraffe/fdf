/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 19:30:48 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_fdf_internal.h"
#include "mlx.h"

void	render_fdf(t_app *app)
{
	app->zoom = 20;
	draw_vertices(app);
	draw_all_edges(app);
	mlx_put_image_to_window(app->mlx, app->window, app->img, 0, 0);
}
