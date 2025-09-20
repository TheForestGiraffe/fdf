/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:31:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "load_map.h"
#include "load_map_internal.h"

static void		count_and_set_nr_columns(char **split_line, t_model *model);
static void		count_and_set_nr_rows(char *line, int fd, t_model *model);

void	parse_map_dimensions(t_model *model, char *filepath)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = try_open(filepath, model);
	line = try_get_next_line(fd, model);
	split_line = try_ft_split(line, model);
	count_and_set_nr_columns(split_line, model);
	count_and_set_nr_rows(line, fd, model);
	close(fd);
}

static void	count_and_set_nr_columns(char **split_line, t_model *model)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		if (split_line[i][0] == '\n')
			break ;
		i++;
	}
	model->columns = i;
	i = 0;
	while (split_line[i])
		free(split_line[i++]);
	free(split_line);
}

static void	count_and_set_nr_rows(char *line, int fd, t_model *model)
{
	while (line)
	{
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			break ;
		}
		model->rows++;
		free(line);
		line = get_next_line(fd);
	}
}
