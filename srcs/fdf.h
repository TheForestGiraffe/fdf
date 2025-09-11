/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/11 12:48:09 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// t_vertex: stores the attributes of a data point.
typedef struct s_vertex
{
	int	x;
	int	y;
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

#endif
