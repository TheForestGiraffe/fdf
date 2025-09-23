/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_mouse_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:27:19 by plima             #+#    #+#             */
/*   Updated: 2025/09/23 19:18:10 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img.h"

int handle_on_mouse_move(int x, int y, void *param)
{
    t_app   *app;

    app = (t_app *)param;
    if (app->view.currently_dragging_with_left_mouse_button)
    {
        app->view.rot_angle_x = (x - app->view.last_mouse_x) * 
            app->view.rot_sensitivity;
        app->view.rot_angle_y = (y - app->view.last_mouse_y) *
            app->view.rot_sensitivity;
        app->view.last_mouse_x = x;
        app->view.last_mouse_y = y;
        render_img(app);
    }
    return (0);
}
