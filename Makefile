# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atetu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 16:11:18 by atetu             #+#    #+#              #
#    Updated: 2020/03/07 14:52:20 by atetu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORK =	-lmlx -framework OpenGL -framework AppKit 

NAME = 		Cub3D

MLX_DIR =	minilibx_opengl/
LIBFT_DIR =	libft/
LIBFT_A =	$(LIBFT_DIR)/libft.a
MLX_A =		$(MLX_DIR)/libmlx.a

SRCS =		srcs/main.c \
			srcs/main_utils.c \
			srcs/parser/parser.c \
		   	srcs/parser/parser_get_next_line.c	\
			srcs/parser/parser_dir.c \
			srcs/parser/parser_dir_utils.c \
			srcs/parser/parser_map.c \
			srcs/parser/parser_map_fill.c \
			srcs/parser/parser_map_utils.c \
			srcs/parser/parser_ceiling_floor.c \
			srcs/parser/parser_utils1_digit.c \
			srcs/parser/parser_utils2_check_char_arg.c \
			srcs/parser/parser_utils2bis_check_char_arg.c \
			srcs/parser/parser_utils3_space.c \
			srcs/parser/parser_utils4_error.c \
			srcs/parser/parser_utils4bis_error.c \
			srcs/parser/parser_position.c \
			srcs/parser/parser_malloc_map.c \
			srcs/check_file/check_map.c \
			srcs/check_file/check_struct.c \
			srcs/init/init_struct.c \
			srcs/init/init_dir.c \
			srcs/init/init_load_tex_images.c \
			srcs/init/init_sprites_color.c \
			srcs/managers/manage_key.c \
			srcs/managers/manage_key_rotation.c \
			srcs/managers/manage_exit.c \
			srcs/managers/manage_exit_save.c \
			srcs/managers/manage_free.c \
			srcs/managers/manage_free_array_maps.c \
			srcs/managers/manage_free_array_maps2.c \
			srcs/raycasting/ray_init.c \
			srcs/raycasting/ray_window.c \
			srcs/raycasting/ray_window_utils.c \
			srcs/raycasting/ray_texture.c\
			srcs/raycasting/ray_sprites.c \
			srcs/save_image/save.c \

OBJS = 		$(SRCS:.c=.o)
INC_PATH = 	-I. -Ilibft/ -Iminilibx_opengl/
CUB3D_H =	-I ./includes

CC =		gcc

RM = 		rm -f

CFLAGS = 	-Wall -Wextra -Werror

COMPILE	= $(CC) $(FLAGS) $(INC_PATH) $(CUB3D_H) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
%.o : %.c 
			$(CC) $(CFLAGS) $(INC_PATH) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(LIBFT_A):
			make -C $(LIBFT_DIR)

$(MLX_A):
			make -C $(MLX_DIR)

$(NAME): 	$(LIBFT_A) $(MLX_A) $(OBJS)
			$(COMPILE) $(OBJS) -o $(NAME)

clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT_DIR}
			make clean -C ${MLX_DIR}

fclean: 	clean
			${RM} ${NAME}
			make fclean -C ${LIBFT_DIR}

re:			fclean all

.PHONY: 	fclean clean all re
