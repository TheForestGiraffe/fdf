/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:03:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMG_INTERNAL_H
# define RENDER_IMG_INTERNAL_H

# include "fdf.h"

void	erase_img(t_img *img, t_view *view);
void	draw_vertices(t_projection *projection, t_view *view, t_img *img);
void	draw_edges(t_app *app);
void	put_pixel(int x, int y, t_view *view, t_img *img);

#endif