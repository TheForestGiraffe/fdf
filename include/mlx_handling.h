/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:46:52 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 19:21:50 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLING_H
# define MLX_HANDLING_H

# include "fdf.h" // for t_app

// mlx_handling.c
void	init_mlx(t_app *app);
void	register_mlx_hooks(t_app *app);
void	init_mlx_img(t_app *app);

#endif