/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlx_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 10:38:53 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include <stdlib.h>
#include <X11/keysym.h>

void	register_mlx_hooks(t_app *app)
{
	mlx_hook(app->window, ON_DESTROY, 0, &handle_close, app);
	mlx_hook(app->window, ON_KEY_PRESS, KEY_PRESS_MASK, &handle_on_key_press, app);
	mlx_hook(app->window, ON_BUTTON_PRESS, BUTTON_PRESS_MASK, 
		&handle_on_button_press, app);	
	mlx_hook(app->window, ON_BUTTON_RELEASE, BUTTON_RELEASE_MASK, 
		&handle_on_button_release, app);
}


//TODO mlx_hook(app->win, 6, 1L<<6, mouse_move, app);   // motion