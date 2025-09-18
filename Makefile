# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/18 14:00:41 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = srcs
OBJS_DIR = objs
SRCS = $(addprefix $(SRCS_DIR)/, fdf.c \
								free_maps.c \
								init_mlx.c \
								init_mlx_img.c \
								project_map.c \
								setup_mlx_hooks.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
HEADER_DIR = include
HEADER = $(HEADER_DIR)/fdf.h

# load_map module
LOAD_MAP_SRCS_DIR = srcs/load_map
LOAD_MAP_SRCS = $(addprefix $(LOAD_MAP_SRCS_DIR)/, free_map_vertices.c \
				load_map.c parse_map_dimensions.c parse_map.c try_ft_split.c \
			 	try_get_next_line.c try_open.c try_init_map.c \
			 	try_init_map_vertices.c)
LOAD_MAP_OBJS_DIR = objs/load_map
LOAD_MAP_OBJS = $(patsubst $(LOAD_MAP_SRCS_DIR)/%.c, \
				$(LOAD_MAP_OBJS_DIR)/%.o, $(LOAD_MAP_SRCS))
PUB_LOAD_MAP_HEADER_DIR = include
PRIV_LOAD_MAP_HEADER_DIR = $(LOAD_MAP_SRCS_DIR)
LOAD_MAP_HEADERS = $(PUB_LOAD_MAP_HEADER_DIR)/fdf_map.h \
					$(PRIV_LOAD_MAP_HEADER_DIR)/fdf_map_internal.h

# render_fdf module
RENDER_FDF_SRCS_DIR = srcs/render_fdf
RENDER_FDF_SRCS = $(addprefix $(RENDER_FDF_SRCS_DIR)/, draw_edges.c \
					draw_vertices.c put_pixel.c render_fdf.c)
RENDER_FDF_OBJS_DIR = objs/render_fdf
RENDER_FDF_OBJS = $(patsubst $(RENDER_FDF_SRCS_DIR)/%.c, \
					$(RENDER_FDF_OBJS_DIR)/%.o, $(RENDER_FDF_SRCS))
PUB_RENDER_FDF_HEADER_DIR = include
PRIV_RENDER_FDF_HEADER_DIR = $(RENDER_FDF_SRCS_DIR)
RENDER_FDF_HEADERS = $(PUB_RENDER_FDF_HEADER_DIR)/render_fdf.h \
						$(PRIV_RENDER_FDF_HEADER_DIR)/render_fdf_internal.h

OBJS_DIRS = $(OBJS_DIR) $(LOAD_MAP_OBJS_DIR) $(RENDER_FDF_OBJS_DIR)

# Libft
LIBFT_DIR = libs/Libft-2.1.0
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

# MiniLibX
LIBMLX_DIR = libs/minilibx-linux
LIBMLX_HEADER_DIR = $(LIBMLX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror -g -I$(HEADER_DIR) -I$(PUB_LOAD_MAP_HEADER_DIR) \
								-I$(PRIV_LOAD_MAP_HEADER_DIR) \
								-I$(PUB_RENDER_FDF_HEADER_DIR) \
								-I$(PRIV_RENDER_FDF_HEADER_DIR) \
								-I$(LIBFT_HEADER_DIR) -I$(LIBMLX_HEADER_DIR)

all: $(OBJS_DIRS) $(NAME)

$(OBJS_DIRS):
	mkdir -p $@

$(NAME): $(OBJS) $(LOAD_MAP_OBJS) $(RENDER_FDF_OBJS) $(LIBFT) $(LIBMLX)
	cc $(CFLAGS) $(OBJS) $(LOAD_MAP_OBJS) $(RENDER_FDF_OBJS) \
		$(LIBFT) $(LIBMLX) -lX11 -lXext -lm \
	-o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

$(LOAD_MAP_OBJS_DIR)/%.o: $(LOAD_MAP_SRCS_DIR)/%.c $(LOAD_MAP_HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(RENDER_FDF_OBJS_DIR)/%.o: $(RENDER_FDF_SRCS_DIR)/%.c $(RENDER_FDF_HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

print:
	@echo $(RENDER_FDF_OBJS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	rm -f $(LOAD_MAP_OBJS)
	rm -rf $(LOAD_MAP_OBJS_DIR)
	rm -f $(RENDER_FDF_OBJS)
	rm -rf $(RENDER_FDF_OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all re clean fclean 
