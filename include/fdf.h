/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:57:03 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "load_map.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_2d_vertex
{
	double				x;
	double				y;
}	t_2d_vertex;

typedef struct s_projection
{
	int				rows;
	int				columns;
	t_2d_vertex		**vertices;
}	t_projection;

typedef struct s_app
{
	void			*mlx;
	void			*window;
	void			*img;
	char			*img_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				zoom;
	int				shift_x;
	int				shift_y;
	t_model			*model;
	t_projection	*projection;
}	t_app;

void			validate_argc(int argc);
t_projection	*project_map(t_model *model);
void			free_models(t_model *model, t_projection *projection);
void			init_mlx(t_app *app);
void			register_mlx_hooks(t_app *app);
void			init_mlx_img(t_app *app);

#endif
