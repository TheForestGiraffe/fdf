/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:13:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

char	**try_ft_split(char *line, t_app *app)
{
	char	**columns;

	columns = ft_split(line, ' ');
	if (!columns)
	{
		free(line);
		destroy_app(app, EXIT_FAILURE);
	}
	return (columns);
}
