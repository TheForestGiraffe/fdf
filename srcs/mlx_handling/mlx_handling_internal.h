/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 07:23:19 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLING_INTERNAL_H
# define MLX_HANDLING_INTERNAL_H

enum {
	ON_DESTROY = 17,
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
};

enum {
	KEY_PRESS_MASK = 1L << 0,
	BUTTON_PRESS_MASK = 1L<<2
};

enum {
	MOUSE_WHEEL_UP = 4,
	MOUSE_WHEEL_DOWN = 5,
	LEFT_ARROW_DOWN = 65361,
	RIGHT_ARROW_DOWN = 65363,
	UP_ARROW_DOWN = 65362,
	DOWN_ARROW_DOWN = 65364
};

int	handle_close(void *param);
int	handle_keydown(int key, void *param);
int	handle_mousedown(int button, int x, int y, void *param);

#endif