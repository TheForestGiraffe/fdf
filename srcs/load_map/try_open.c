/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:05:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

int	try_open(char *filepath, t_app *app)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("try_open failed.");
		destroy_app(app, EXIT_FAILURE);
	}
	return (fd);
}
