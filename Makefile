# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/09 16:56:45 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, fdf.c load_map.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

HEADER_DIR = $(SRCS_DIR)
HEADER = $(SRCS_DIR)/fdf.h

LIBFT_DIR = libs/Libft-2.0.0
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

LIBMLX_DIR = libs/minilibx-linux
LIBMLX_HEADER_DIR = $(LIBMLX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -I$(LIBFT_HEADER_DIR) \
							   -I$(LIBMLX_HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT) $(LIBMLX)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(LIBMLX_DIR)

re: fclean all

.PHONY: all re clean fclean 

