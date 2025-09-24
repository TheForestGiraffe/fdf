/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 10:39:03 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"

t_model	*create_model(void)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
	{
		perror("create_model: malloc failed.");
		exit(EXIT_FAILURE);
	}
	model->rows = 0;
	model->columns = 0;
	model->vertices = NULL;
	return (model);
}
