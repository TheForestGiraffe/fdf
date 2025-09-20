/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:27:27 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 18:14:59 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MLX_HANDLING_H
# define MLX_HANDLING_H

enum {
	ON_DESTROY = 17,
	ON_KEYDOWN = 2
};

enum {
    KEY_PRESS_MASK = 1L << 0,
};

int	handle_close(void *param);
int	handle_keydown(int key, void *param);

#endif