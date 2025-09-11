/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 01:07:00 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_map.h"
#include "fdf_map_internal.h"

char	*try_get_next_line(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		free_map_vertices(map);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (line);
}
