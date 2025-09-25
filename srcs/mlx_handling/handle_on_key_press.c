/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 16:57:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include "render_img.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdbool.h>

static bool	is_translation_key(int key, t_view *view);
static bool	is_rotation_key(int key, t_view *view);
static bool	is_projection_type_key(int key, t_view *view);

int	handle_on_key_press(int key, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (key == XK_Escape)
		handle_close(app);
	if (is_translation_key(key, &app->view))
		render_img(app);
	if (is_rotation_key(key, &app->view))
		render_img(app);
	if (is_projection_type_key(key, &app->view))
		render_img(app);
	return (0);
}

static bool	is_translation_key(int key, t_view *view)
{
	if (key == LEFT_ARROW_PRESS)
	{
		view->shift_x -= view->translation_step;
		return (true);
	}
	if (key == RIGHT_ARROW_PRESS)
	{
		view->shift_x += view->translation_step;
		return (true);
	}
	if (key == UP_ARROW_PRESS)
	{
		view->shift_y -= view->translation_step;
		return (true);
	}
	if (key == DOWN_ARROW_PRESS)
	{
		view->shift_y += view->translation_step;
		return (true);
	}
	return (false);
}

static bool	is_rotation_key(int key, t_view *view)
{
	if (key == XK_a)
		view->rot_angle_y -= view->rot_step;
	else if (key == XK_d)
		view->rot_angle_y += view->rot_step;
	else if (key == XK_w)
		view->rot_angle_x += view->rot_step;
	else if (key == XK_s)
		view->rot_angle_x -= view->rot_step;
	else if (key == XK_r)
		view->rot_angle_z += view->rot_step;
	else if (key == XK_f)
		view->rot_angle_z -= view->rot_step;
	if (key == XK_a || key == XK_d || key == XK_w || key == XK_s || 
		key == XK_r || key == XK_f)
		return (true);
	else
		return (false);
}

static bool	is_projection_type_key(int key, t_view *view)
{
	if (key == XK_z)
		view->projection_type = TOP_VIEW;
	else if (key == XK_x)
		view->projection_type = SIDE_VIEW;
	else if (key == XK_y)
		view->projection_type = FRONT_VIEW;
	else if (key == XK_i)
		view->projection_type = ISO_VIEW;
	if (key == XK_z || key == XK_y || key == XK_x || key == XK_i)
		return (true);
	else
		return (false);
}
