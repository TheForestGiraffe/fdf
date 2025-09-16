/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/16 17:14:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fdf_map.h"
#include "fdf.h"

void	print_map(t_map *map); //TODO
void	print_proj_map(t_proj_map *proj_map); //TODO

static void	validate_nr_args(int argc);

int main(int argc, char **argv)
{
	t_app		app;
	
	validate_nr_args(argc); // TODO: MOVE?
	app.map = load_map(argv[1]);
	app.proj_map = project_map(app.map);

	init_mlx(&app);
	setup_mlx_hooks(&app);
	init_mlx_img(&app);
	render_proj_map(&app);

	print_map(app.map);
	print_proj_map(app.proj_map);

	mlx_loop(app.mlx);
	
	return 0;
}

static void	validate_nr_args(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("main.c: invalid number of input arguments.", 2);
		exit(EXIT_FAILURE);
	}
}

// TODO: Remove/Move
void	print_map(t_map *map)
{
	int	x;
	int	y;

	ft_printf("\n");
	ft_printf("Nr. of columns: %i\n", map->nr_columns);
	ft_printf("Nr. of rows: %i\n", map->nr_rows);
	ft_printf("Vertices:\n");
	y = 0;
	while (y < map->nr_rows)
	{
		x = 0;
		while (x < map->nr_columns)
		{
			ft_printf("%i ", map->vertices[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}	
}

void	print_proj_map(t_proj_map *proj_map)
{
	int	x;
	int	y;

	ft_printf("\n");
	ft_printf("Nr. of columns: %i\n", proj_map->nr_columns);
	ft_printf("Nr. of rows: %i\n", proj_map->nr_rows);
	ft_printf("Projected Vertices:\n");
	y = 0;
	while (y < proj_map->nr_rows)
	{
		x = 0;
		while (x < proj_map->nr_columns)
		{
			ft_printf("x: %i, ", proj_map->proj_vertices[y][x].x);
			ft_printf("y: %i  \n", proj_map->proj_vertices[y][x].y);
			x++;
		}
		ft_printf("\n");
		y++;
	}	
}
