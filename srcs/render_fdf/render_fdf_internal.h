/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fdf_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 13:45:03 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef RENDER_FDF_INTERNAL_H
# define RENDER_FDF_INTERNAL_H

void	draw_vertices(t_app *app);
void	put_pixel(t_app *app, int x, int y, int color);
void	draw_edges(t_app *app);

#endif