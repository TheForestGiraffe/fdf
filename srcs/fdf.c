/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 03:09:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "load_map.h"
#include "fdf.h"
#include "render_img.h"
#include "mlx_handling.h"

int	main(int argc, char **argv)
{
	t_app		app;

	validate_argc(argc);
	app.model = load_map(argv[1]);
	app.projection = init_projection(app.model);
	init_view(app.projection, &app.view);
	apply_isometric_projection(&app);
	init_mlx(&app);
	register_mlx_hooks(&app);
	init_mlx_img(app.mlx, &app.view, &app.img);
	render_img(&app);
	mlx_loop(app.mlx);
	return (0);
}


// INITIALIZE VIEW  -zscale 0.1