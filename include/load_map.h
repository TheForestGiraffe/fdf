/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:57:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_H
# define LOAD_MAP_H

typedef struct s_3d_vertex
{
	int	z;
}	t_3d_vertex;

typedef struct s_model
{
	int			rows;
	int			columns;
	t_3d_vertex	**vertices;
}	t_model;

t_model	*load_map(char *filepath);
void	free_model_vertices(t_model *model);

#endif
