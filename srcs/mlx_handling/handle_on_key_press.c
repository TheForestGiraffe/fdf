/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 13:32:12 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include "render_img.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	handle_on_key_press(int key, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (key == XK_Escape)
		handle_close(app);
	if (key == LEFT_ARROW_PRESS)
        app->view.shift_x -= app->view.translation_step;
    if (key == RIGHT_ARROW_PRESS)
        app->view.shift_x += app->view.translation_step;
    if (key == UP_ARROW_PRESS)
        app->view.shift_y -= app->view.translation_step;
    if (key == DOWN_ARROW_PRESS)
    app->view.shift_y += app->view.translation_step;
	render_img(app);
	return (0);
}