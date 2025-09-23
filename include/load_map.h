/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/23 16:58:45 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_H
# define LOAD_MAP_H

typedef struct s_3d_vertex
{
	int	x;
	int	y;
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
