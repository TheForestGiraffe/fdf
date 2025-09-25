/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:30:21 by pecavalc         ###   ########.fr       */
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
	init_app(&app);
	app.model = load_map(argv[1], &app);
	app.model_transformed = create_model_transformed(&app);
	app.projection = create_projection(&app);
	init_mlx(&app);
	init_mlx_window(&app);
	register_mlx_hooks(&app);
	init_mlx_img(app.mlx, &app.view, &app.img);
	render_img(&app);
	mlx_loop(app.mlx);
	return (0);
}
