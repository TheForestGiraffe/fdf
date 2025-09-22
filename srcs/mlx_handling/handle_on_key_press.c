/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 10:37:16 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mlx_handling_internal.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	handle_on_key_press(int key, void *param)
{
	if (key == XK_Escape)
		handle_close(param);
	if (key == LEFT_ARROW_PRESS || key == RIGHT_ARROW_PRESS || 
		key == UP_ARROW_PRESS || key == DOWN_ARROW_PRESS)
		translate_projection(key, param);
	return (0);
}