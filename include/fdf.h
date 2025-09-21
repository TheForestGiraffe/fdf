/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 04:55:11 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "load_map.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_2d_vertex {
	double				x;
	double				y;
}	t_2d_vertex;

typedef struct s_projection {
	int				rows;
	int				columns;
	t_2d_vertex		**vertices;
}	t_projection;

typedef struct s_view {
	int		width;
	int		height;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		color;
	float	scale_z;
}			t_view;

typedef struct s_img {
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_app
{
	void			*mlx;
	void			*window;
	t_img			img;
	t_view			view;
	t_model			*model;
	t_projection	*projection;
}	t_app;

void			validate_argc(int argc);
t_projection	*init_projection(t_model *model);
void			init_view(t_projection *projection, t_view *view);
void			apply_isometric_projection(t_app *app);
void			init_mlx(t_app *app);
void			register_mlx_hooks(t_app *app);
void			init_mlx_img(void *mlx, t_view *view, t_img *img);
void			free_models(t_model *model, t_projection *projection);

#endif
