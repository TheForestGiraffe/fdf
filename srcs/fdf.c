/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/23 19:48:50 by plima            ###   ########.fr       */
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
	//TODO: 
	// - Initialize transformed model
	// - Ensure transformed model is freed properly
	// - Update applyu_projection function, zoom, shift, etc. to be applied over transformed model.
	// - Implement rotation z with keyboard?
	app.projection = init_projection(app.model);
	init_view(app.projection, &app.view);
	init_mlx(&app);
	init_mlx_window(&app);
	register_mlx_hooks(&app);
	init_mlx_img(app.mlx, &app.view, &app.img);
	render_img(&app);
	mlx_loop(app.mlx);
	return (0);
}
