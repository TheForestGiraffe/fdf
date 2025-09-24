/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 15:01:14 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "load_map.h"
#include "fdf.h"
#include "render_img.h"
#include "mlx_handling.h"


//TODO: 
//- model transformed rows and cols from model somehow
//- finalize alloc projection, create projection..



int	main(int argc, char **argv)
{
	t_app		app;

	validate_argc(argc);
	init_app(&app);
	app.model = load_map(argv[1], &app);
	app.model_transformed = create_model(&app); 
	app.projection = create_projection(&app);

	//TODO: 
	// - Update applyu_projection function, zoom, shift, etc. to be applied over transformed model.
	// - Implement rotation z with keyboard?
	init_mlx(&app);
	init_mlx_window(&app);
	register_mlx_hooks(&app);
	init_mlx_img(app.mlx, &app.view, &app.img);
	render_img(&app);
	mlx_loop(app.mlx);
	return (0);
}
