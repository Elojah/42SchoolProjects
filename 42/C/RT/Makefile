#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2014/03/23 15:36:52 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = raytracer
FILES = ft_getfloats.c ft_getrgba.c ft_getvect.c ft_getobj.c ft_getscene.c \
		ft_isgood.c ft_atof.c ft_import.c \
		ft_rotate_vect.c ft_addsub_vect.c ft_cross_product.c ft_dot_product.c \
		ft_solve_polynomials.c ft_obj_trans.c ft_inter_vect.c \
		ft_intersection_plane.c ft_intersection_sphere.c \
		ft_intersection_cylinder.c ft_intersection_cone.c \
		ft_intersection_torus.c ft_intersection_disk.c \
		ft_intersection_triangle.c ft_interobj.c ft_mapobj.c ft_normalobj.c \
		ft_nearest_object.c ft_reflection.c ft_transparency.c ft_subtract.c \
		ft_refraction.c \
		ft_tex_color.c ft_phong_shading.c ft_shadow.c ft_getcolor.c \
		ft_put_pixel_to_image.c ft_draw_raytracer.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/raytracer.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L./libft/ -lft -L/usr/X11/lib -lXext -lX11 -lmlx -lm

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) -Iinc -I./libft -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
