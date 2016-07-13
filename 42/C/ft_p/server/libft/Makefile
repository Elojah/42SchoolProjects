#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2015/05/04 12:27:42 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstlen.c ft_get_line.c \
		ft_error.c ft_atof.c ft_free_array_str.c ft_find_last.c send_data.c \
		read_data.c read_files.c send_data.c send_files.c append_msg.c \

SRCS = $(addprefix src/, $(FILES))
OBJS = $(SRCS:src/%.c=obj/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ include/libft.h~
CC = clang
CFLAGS = -Wall -Wextra -Werror -arch x86_64
IFLAGS = -I./include/

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	mkdir -p lib
	ar rc lib/$(NAME) $(OBJS)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p obj

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf obj

fclean: clean
	/bin/rm -f lib/$(NAME)

re: fclean all
