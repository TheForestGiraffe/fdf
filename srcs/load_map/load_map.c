/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 12:29:43 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "load_map.h"
#include "load_map_internal.h"

t_model	*load_map(char *filepath, t_app *app)
{
	t_model	*model;

	model = create_model(app);
	parse_map_dimensions(model, filepath);
	try_init_model_vertices(model);
	parse_map(model, filepath);
	return (model);
}
