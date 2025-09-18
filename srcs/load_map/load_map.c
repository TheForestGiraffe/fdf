/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:40:16 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_map.h"
#include "load_map_internal.h"

t_map	*load_map(char *filepath)
{
	t_map	*map;

	map = try_init_map();
	parse_map_dimensions(map, filepath);
	try_init_map_vertices(map);
	parse_map(map, filepath);
	return (map);
}
