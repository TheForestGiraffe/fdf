/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/11 12:59:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	print_map(t_map *map);

int main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr_fd("main.c: invalid number of input arguments.", 2);
		return (1);
	}
	map = load_map(argv[1]);

	print_map(map); //TODO: remove test

	return 0;
}

void	print_map(t_map *map)
{
	int	x;
	int	y;

	ft_printf("\n");
	ft_printf("Nr. of columns: %i\n"), map->nr_columns);
	ft_printf("Nr. of rows: %i\n", map->nr_rows);
	ft_printf("Vertices:\n");
	y = 0;
	while (y <= map->nr_rows)
	{
		x = 0;
		while (x <= map->nr_columns)
		{
			ft_printf("%i ", map->vertices[x][y].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}	
}

