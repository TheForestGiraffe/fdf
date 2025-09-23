/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/23 19:14:36 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMG_INTERNAL_H
# define RENDER_IMG_INTERNAL_H

# include "fdf.h"

typedef struct s_edge {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
}		t_edge;

void	render_img(t_app *app);
void	erase_img(t_img *img, t_view *view);
void    apply_rotation_to_model(t_app *app);
void	apply_isometric_projection_to_model(t_app *app);
void	apply_translation_to_projection(t_app *app);
void	apply_zoom_to_projection(t_app *app);
void	render_all_edges(t_app *app);
void	put_pixel(int x, int y, t_view *view, t_img *img);

#endif