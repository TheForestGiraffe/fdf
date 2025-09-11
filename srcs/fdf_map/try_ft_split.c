/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 01:06:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_map.h"
#include "fdf_map_internal.h"

char	**try_ft_split(char *line, t_map *map)
{
	char	**columns;

	columns = ft_split(line, ' ');
	if (!columns)
	{
		free(line);
		free_map_vertices(map);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (columns);
}
