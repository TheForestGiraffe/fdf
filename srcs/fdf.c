/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 21:18:09 by pecavalc         ###   ########.fr       */
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
	app.proj_map = project_map(app.model);
	init_mlx(&app);
	register_mlx_hooks(&app);
	init_mlx_img(&app);
	app.zoom = 20; // TODO initialize somewhere else
	render_img(&app);
	mlx_loop(app.mlx);
	return (0);
}
