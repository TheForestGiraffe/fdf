/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/18 10:40:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_INTERNAL_H
# define LOAD_MAP_INTERNAL_H

#include "load_map.h"

t_map	*try_init_map(void);
void	try_init_map_vertices(t_map *map);
void	parse_map_dimensions(t_map *map, char *filepath);
void 	parse_map(t_map *map, char *filepath);
int		try_open(char *filepath, t_map *map);
char	*try_get_next_line(int fd, t_map *map);
char	**try_ft_split(char *line, t_map *map);

#endif