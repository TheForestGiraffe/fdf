/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_mlx_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 19:20:36 by pecavalc         ###   ########.fr       */
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
	mlx_hook(app->window, ON_KEYDOWN, KEY_PRESS_MASK, &handle_keydown, app);
	mlx_hook(app->window, ON_MOUSEDOWN, BUTTON_PRESS_MASK, &handle_mousedown, app);
}
