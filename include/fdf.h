/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/15 11:31:34 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "fdf_map.h"

typedef struct s_proj_vertex
{
	int	x;
	int y;
}	t_proj_vertex;

typedef struct s_proj_map
{
	int				nr_rows;
	int				nr_columns;
	t_proj_vertex	**proj_vertices;
}	t_proj_map;

t_proj_map	*project_map(t_map *map);
void		free_maps(t_map *map, t_proj_map *proj_map);

#endif
