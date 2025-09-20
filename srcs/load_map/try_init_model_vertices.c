/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_init_map_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:38:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"

void	try_init_model_vertices(t_model *model)
{
	int	y;

	model->vertices = (t_vertex **)malloc(model->rows * sizeof(t_vertex *));
	if (!model->vertices)
	{
		free(model);
		ft_putstr_fd("init_model_vertices: 1st malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < model->rows)
	{
		model->vertices[y] = malloc(model->columns * sizeof(t_vertex));
		if (!model->vertices[y])
		{
			while (y > 0)
				free(model->vertices[--y]);
			free(model->vertices);
			free(model);
			ft_putstr_fd("init_model_vertices: 2nd malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}
