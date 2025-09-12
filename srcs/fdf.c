/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/12 01:48:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_map.h"

void	print_map(t_map *map); //TODO

static void	validate_nr_args(int argc);

int main(int argc, char **argv)
{
	t_map	*map;

	validate_nr_args(argc);
	map = load_map(argv[1]);

	print_map(map); //TODO: remove test

	free_map_vertices(map);
	free(map);
	
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

