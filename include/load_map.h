/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 15:02:07 by pecavalc         ###   ########.fr       */
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

t_model	*load_map(char *filepath, t_app *app);
t_model *create_model(t_app *app);

#endif
