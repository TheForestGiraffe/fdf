/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:52:00 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_projection	*create_projection(t_app *app)
{
	t_projection	*projection;

	projection = alloc_projection(app);
	init_projection(&projection, app->model);
	return (projection);
}
