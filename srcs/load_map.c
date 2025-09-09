/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/09 17:02:15 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Allocate t_map map on the heap for proper return.

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "fdf.h"

t_map	*load_map(char *filepath)
{
	int		fd;
	t_map	map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("load_map");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (&map);
}
