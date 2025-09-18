/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:41:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

int	try_open(char *filepath, t_map *map)
{
	int	fd;
	
	fd = open(filepath, O_RDONLY );
	if (fd < 0)
	{
		perror("try_open");
		free_map_vertices(map);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
