/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:14:38 by pecavalc         ###   ########.fr       */
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
	MOUSE_WHEEL_DOWN = 5
};

int	handle_close(void *param);
int	handle_keydown(int key, void *param);
int	handle_mousedown(int button, int x, int y, void *param);

#endif