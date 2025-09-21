/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:49:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 01:27:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, t_view *view, t_img *img)
{
	char	*pixel_address;

	if (x < 0 || x >= view->width || y < 0 || y >= view->height)
		return ;
	pixel_address = img->address + (y * img->line_size) 
		+ (x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel_address = view->color;
}
