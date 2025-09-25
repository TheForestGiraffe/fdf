/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 16:55:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "load_map.h"
#include "fdf.h"

static void	apply_isometric_projection(t_app *app);
static void	apply_parallel_projection_top(t_app *app);
static void	apply_parallel_projection_side(t_app *app);
static void	apply_parallel_projection_front(t_app *app);

void	apply_projection(t_app *app)
{
	if (app->view.projection_type == ISO_VIEW)
		apply_isometric_projection(app);
	else if (app->view.projection_type == SIDE_VIEW)
		apply_parallel_projection_side(app);
	else if (app->view.projection_type == FRONT_VIEW)
		apply_parallel_projection_front(app);
	else if (app->view.projection_type == TOP_VIEW)
		apply_parallel_projection_top(app);
}

static void	apply_isometric_projection(t_app *app)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	j = 0;
	while (j < app->model_transformed->rows)
	{
		i = 0;
		while (i < app->model_transformed->columns)
		{
			x = app->model_transformed->vertices[j][i].x;
			y = app->model_transformed->vertices[j][i].y;
			z = app->model_transformed->vertices[j][i].z;
			app->projection->vertices[j][i].x = (x - y) * cos(M_PI / 6);
			app->projection->vertices[j][i].y = (x + y) * sin(M_PI / 6) 
				- (z * app->view.scale_z);
			i++;
		}
		j++;
	}
}

static void	apply_parallel_projection_top(t_app *app)
{
	(void) app;
}

static void	apply_parallel_projection_side(t_app *app)
{
	(void) app;
}

static void	apply_parallel_projection_front(t_app *app)
{
	(void) app;
}
