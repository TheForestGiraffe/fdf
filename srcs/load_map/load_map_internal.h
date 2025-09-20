/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:27:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_INTERNAL_H
# define LOAD_MAP_INTERNAL_H

# include "load_map.h"

t_model	*try_init_model(void);
void	try_init_model_vertices(t_model *model);
void	parse_map_dimensions(t_model *model, char *filepath);
void	parse_map(t_model *model, char *filepath);
int		try_open(char *filepath, t_model *model);
char	*try_get_next_line(int fd, t_model *map);
char	**try_ft_split(char *line, t_model *map);

#endif