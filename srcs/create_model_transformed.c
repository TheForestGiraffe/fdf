/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_transformed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 14:10:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "load_map.h"

t_model	*create_model_transformed(t_app *app)
{
	t_model	*model_transformed;

	model_transformed = alloc_model(app);
	init_model_transformed(model_transformed, app->model);
	alloc_model_vertices(model_transformed, app);
	copy_model_vertices(app->model, model_transformed);
	return (model_transformed);
}
