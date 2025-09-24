/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:11:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"
#include "fdf.h"

char	*try_get_next_line(int fd, t_app *app)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		ft_pustr_fd("get_next_line: returned null.\n");
		destroy_app(app, EXIT_FAILURE);
	}
	return (line);
}
