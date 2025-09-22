/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:55:59 by plima             #+#    #+#             */
/*   Updated: 2025/09/22 07:58:01 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img.h"

void    update_view(t_app *app)
{
    apply_isometric_projection(app);
    render_img(app);
}
