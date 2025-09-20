/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:21:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "load_map.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// t_proj_vertex: stores the attributes of a projected data point.
typedef struct s_proj_vertex
{
	double				x;
	double				y;
	unsigned int		color;
}	t_proj_vertex;

// t_proj_map: stores the attributes of a projected map file.
typedef struct s_proj_map
{
	int				nr_rows;
	int				nr_columns;
	t_proj_vertex	**proj_vertices;
}	t_proj_map;

// t_env: stores the application data and state variables
typedef struct s_app
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*img_address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	int			zoom;
	int			shift_x;
	int			shift_y;
	t_model		*model;
	t_proj_map	*proj_map;
}	t_app;

void		validate_argc(int argc);
t_proj_map	*project_map(t_model *model);
void		free_models(t_model *model, t_proj_map *proj_map);
void		init_mlx(t_app *app);
void		setup_mlx_hooks(t_app *app);
void		init_mlx_img(t_app *app);

#endif
