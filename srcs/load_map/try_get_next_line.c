/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:35:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

char	*try_get_next_line(int fd, t_model *model)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		free_model_vertices(model);
		free(model);
		exit(EXIT_FAILURE);
	}
	return (line);
}
