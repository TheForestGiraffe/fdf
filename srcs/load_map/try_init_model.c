/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_init_model.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:19:30 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"

t_model	*try_init_model(void)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
	{
		ft_putstr_fd("load_map: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	model->rows = 0;
	model->columns = 0;
	model->vertices = NULL;
	return (model);
}
