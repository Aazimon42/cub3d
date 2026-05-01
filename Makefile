# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-maio <edi-maio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 19:03:13 by edi-maio          #+#    #+#              #
#    Updated: 2026/05/01 22:07:44 by edi-maio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
NAME = cub3d
LIBFT = libft/libft.a
SRC_DIR = srcs/
SRCS = $(SRC_DIR)main.c \
	   $(SRC_DIR)mapparser.c \
	   $(SRC_DIR)rgb.c \
	   $(SRC_DIR)utils.c \
	   $(SRC_DIR)map.c \
	   $(SRC_DIR)display.c

MLX = mlx_linux/libmlx.a
MLX_FLAGS = -lX11 -lXext

OBJ_DIR = objs/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(LIBFT):
	make -C libft all

$(MLX):
	make -C mlx_linux all

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)
	make -C libft clean
	make -C mlx_linux clean

clean:
	rm -rf $(OBJ_DIR)
	make -C libft fclean

re: fclean all

.PHONY: all fclean clean re