/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 13:45:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*pixel_address;

	if (x < 0 || x >= app->width || y < 0 || y >= app->height)
		return ;
	pixel_address = app->img_address + (y * app->size_line)
									 + (x * app->bits_per_pixel/8);
	*(unsigned int *)pixel_address = color;
}