/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:29:45 by plima             #+#    #+#             */
/*   Updated: 2025/09/22 08:10:37 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_handling_internal.h"
#include "render_img.h"

void    translate_projection(int key, void *param)
{
    t_app   *app;

    app = (t_app *)param;
    if (key == LEFT_ARROW_DOWN)
        app->view.shift_x -= app->view.translation_step;
    if (key == RIGHT_ARROW_DOWN)
        app->view.shift_x += app->view.translation_step;
    if (key == UP_ARROW_DOWN)
        app->view.shift_y += app->view.translation_step;
    if (key == DOWN_ARROW_DOWN)
        app->view.shift_y -= app->view.translation_step;
    update_view(app);
}
