/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/22 13:29:37 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLING_INTERNAL_H
# define MLX_HANDLING_INTERNAL_H

typedef enum e_events {
	ON_DESTROY = 17,
	ON_KEY_PRESS = 2,
	ON_BUTTON_PRESS = 4,
	ON_BUTTON_RELEASE = 5,
	ON_MOUSE_MOVE = 6
}	t_events;

typedef enum e_masks {
	KEY_PRESS_MASK = 1L << 0,
	BUTTON_PRESS_MASK = 1L<<2,
	BUTTON_RELEASE_MASK = 1L<<3,
	MOUSE_MOVE_MASK = 1L<<6
}	t_masks;

typedef enum e_buttons {
	MOUSE_WHEEL_UP_BUTTON = 4,
	MOUSE_WHEEL_DOWN_BUTTON = 5,
	RIGHT_MOUSE_BUTTON = 3,
}	t_buttons;

typedef enum e_keys {
	LEFT_ARROW_PRESS = 65361,
	RIGHT_ARROW_PRESS = 65363,
	UP_ARROW_PRESS = 65362,
	DOWN_ARROW_PRESS = 65364
}	t_keys;

int	handle_close(t_app *app);
int	handle_on_key_press(int key, void *param);
int	handle_on_button_press(int button, int x, int y, void *param);
int	handle_on_button_release(int button, int x, int y, void *param);
int	handle_on_mouse_move(int x, int y, void *param);

#endif