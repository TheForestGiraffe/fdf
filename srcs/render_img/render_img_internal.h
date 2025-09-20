/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 19:37:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMG_INTERNAL_H
# define RENDER_IMG_INTERNAL_H

#include "fdf.h"

void	erase_img(t_app *app);
void	draw_vertices(t_app *app);
void	put_pixel(t_app *app, int x, int y, int color);
void	draw_all_edges(t_app *app);

#endif