/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:02:10 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 00:56:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_projection *projection, t_view *view)
{
	view->width = 800;
	view->height = 600;
	view->zoom = 20;
	view->shift_x = (view->width) / 2 - (projection->columns * view->zoom) / 2;
	view->shift_y = (view->height) / 2 - (projection->rows * view->zoom) / 2;
	view->scale_z = 0.1;
	view->color = 0x00FFFFFF;
}
