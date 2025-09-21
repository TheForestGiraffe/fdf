/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousedown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:31:24 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img.h"
#include "mlx_handling_internal.h"

int	handle_mousedown(int button, int x, int y, void *param)
{
	t_app	*app;

	(void)x;
	(void)y;
	app = (t_app *)param;
	if (button == MOUSE_WHEEL_DOWN)
		app->view.zoom -= 1;
	if (button == MOUSE_WHEEL_UP)
		app->view.zoom += 1;
	apply_isometric_projection(app);
	render_img(app);
	return (0);
}