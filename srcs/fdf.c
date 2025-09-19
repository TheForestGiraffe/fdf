/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/19 14:48:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "load_map.h"
#include "fdf.h"
#include "render_fdf.h"

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
	render_fdf(&app);

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
