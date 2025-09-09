/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/09 15:57:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	*map;

	map = load_map(argv[1]);
	//TODO: Handle NULL map returned


    return 0;
}


