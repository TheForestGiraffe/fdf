/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:35:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 12:03:58 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialize all variables in app, incl. pointers to NULL.
 * 
 * Setting NULL pointers allows calling free/destroy at any point, also when one
 * or more variables were not yet allocated, as freeing a NULL pointer is a
 * defined behavior.
 * 
*/

#include "fdf.h"
#include <stddef.h>

void	init_app(t_app *app)
{
	app->mlx = NULL;
	app->window = NULL;
	init_img(&app->img);
	init_view(&app->view);
	app->model = NULL;
	app->model_transformed = NULL;
	app->projection = NULL;
}
