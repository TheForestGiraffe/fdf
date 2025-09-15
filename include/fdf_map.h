/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 01:13:49 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H

// t_vertex: stores the attributes of a data point.
typedef struct s_vertex
{
    int x;
    int y;
	int	z;
}	t_vertex;

// t_map: stores the attributes of a loaded map file.
typedef struct s_map
{
	int			nr_rows;
	int			nr_columns;
	t_vertex	**vertices;
}	t_map;

t_map	*load_map(char *filepath);
void	free_map_vertices(t_map *map);

#endif
