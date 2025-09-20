/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:55:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "load_map.h"
#include "fdf.h"

// Separate into initialize projected model and compute projection

static t_projection	*try_init_projection(t_model *model);
static void			try_init_projection_vertices(t_model *model, t_projection *projection);
static void			fill_projection(t_model *model, t_projection *projection);

t_projection	*project_map(t_model *model)
{
	t_projection	*projection;

	projection = try_init_projection(model);
	try_init_projection_vertices(model, projection);
	fill_projection(model, projection);
	return (projection);
}

static t_projection	*try_init_projection(t_model *model)
{
	t_projection	*projection;

	projection = (t_projection *)malloc(sizeof(t_projection));
	if (!projection)
	{
		free_models(model, projection);
		ft_putstr_fd("try_init_projected_map: failed to allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	projection->rows = model->rows;
	projection->columns = model->columns;
	projection->vertices = NULL;
	return (projection);
}

static void	try_init_projection_vertices(t_model *model, t_projection *projection)
{
	int	y;
	int	size;	

	size = projection->rows * sizeof(t_2d_vertex *);
	projection->vertices = (t_2d_vertex **)malloc(size);
	if (!projection->vertices)
	{
		free_models(model, projection);
		ft_putstr_fd("try_init_projection_vertices: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	size = projection->columns * sizeof(t_2d_vertex);
	y = 0;
	while (y < projection->rows)
	{
		projection->vertices[y] = (t_2d_vertex *)malloc(size);
		if (!projection->vertices[y])
		{
			while (y > 0)
				free(projection->vertices[--y]);
			free(projection->vertices);
			projection->vertices = NULL;
			free_models(model, projection);
			ft_putstr_fd("try_init_proj_map_vertices: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

// Convention adopted in parse_map: y = row, x = column

static void	fill_projection(t_model *model, t_projection *projection)
{
	int		x;
	int		y;
	float	z_scale;

	y = 0;
	z_scale = 0.1;
	while (y < projection->rows)
	{
		x = 0;
		while (x < projection->columns)
		{
			projection->vertices[y][x].x = (x - y) * cos(M_PI / 6);
			projection->vertices[y][x].y = (x + y) * sin(M_PI / 6) - (model->vertices[y][x].z * z_scale);
			x++;
		}
		y++;
	}
}
