/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:02:10 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 12:38:04 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_projection *projection, t_view *view)
{
	view->width = 1280;
	view->height = 1024;
	view->zoom = 20;
	view->zoom_step = 2;
	view->shift_x = (view->width) / 2 - (projection->columns * view->zoom) / 2;
	view->shift_y = (view->height) / 2 - (projection->rows * view->zoom) / 2;
	view->scale_z = 0.2;
	view->translation_step = 10;
	view->rot_angle_x = 0;
	view->rot_angle_y = 0;
	view->rot_sensitivity = 0.005;
	view->color = 0x00FFFF00;
}
