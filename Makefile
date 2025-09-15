# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plima <plima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/15 11:32:12 by plima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = srcs
OBJS_DIR = objs
SRCS = $(addprefix $(SRCS_DIR)/, fdf.c free_maps.c project_map.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
HEADER_DIR = include
HEADER = $(HEADER_DIR)/fdf.h

# load_map
LOAD_MAP_SRCS_DIR = srcs/fdf_map
LOAD_MAP_SRCS = $(addprefix $(LOAD_MAP_SRCS_DIR)/, free_map_vertices.c \
				load_map.c parse_map_dimensions.c parse_map.c try_ft_split.c \
			 	try_get_next_line.c try_open.c try_init_map.c \
			 	try_init_map_vertices.c)
LOAD_MAP_OBJS_DIR = objs/fdf_map
LOAD_MAP_OBJS = $(patsubst $(LOAD_MAP_SRCS_DIR)/%.c, \
				$(LOAD_MAP_OBJS_DIR)/%.o, $(LOAD_MAP_SRCS))
PUB_LOAD_MAP_HEADER_DIR = include
PRIV_LOAD_MAP_HEADER_DIR = $(LOAD_MAP_SRCS_DIR)
LOAD_MAP_HEADERS = $(PUB_LOAD_MAP_HEADER_DIR)/fdf_map.h \
				   $(PRIV_LOAD_MAP_HEADER_DIR)/fdf_map_internal.h

# Libft
LIBFT_DIR = libs/Libft-2.0.2
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

# MiniLibX
LIBMLX_DIR = libs/minilibx-linux
LIBMLX_HEADER_DIR = $(LIBMLX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -I$(PUB_LOAD_MAP_HEADER_DIR) \
							   -I$(PRIV_LOAD_MAP_HEADER_DIR) \
							   -I$(LIBFT_HEADER_DIR) -I$(LIBMLX_HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LOAD_MAP_OBJS) $(LIBFT) $(LIBMLX)
	cc $(CFLAGS) $(OBJS) $(LOAD_MAP_OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LOAD_MAP_OBJS_DIR)/%.o: $(LOAD_MAP_SRCS_DIR)/%.c $(LOAD_MAP_HEADERS)
	mkdir -p $(LOAD_MAP_OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	rm -f $(LOAD_MAP_OBJS)
	rm -rf $(LOAD_MAP_OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all re clean fclean 

