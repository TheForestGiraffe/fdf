/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keydown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 08:00:45 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	handle_keydown(int key, void *param)
{
	if (key == XK_Escape)
		handle_close(param);
	if (key == LEFT_ARROW_DOWN || key == RIGHT_ARROW_DOWN || 
		key == UP_ARROW_DOWN || key == DOWN_ARROW_DOWN)
		translate_projection(key, param);
	return (0);
}