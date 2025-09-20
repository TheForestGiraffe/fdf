/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousedown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:22:55 by pecavalc         ###   ########.fr       */
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
		app->zoom -= 1;
	if (button == MOUSE_WHEEL_UP)
		app->zoom += 1;
	render_img(app);
	return (0);
}