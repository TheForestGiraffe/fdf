/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:41:28 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"

t_map	*try_init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("load_map: failed to allocate memory", 2);
		exit(EXIT_FAILURE);
	}
	map->nr_rows = 0;
	map->nr_columns = 0;
	map->vertices = NULL;
	return (map);
}
