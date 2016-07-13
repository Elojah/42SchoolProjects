NAME = ft_minishell1

CFLAGS = -Wall -Werror -Wextra -O3 -g

FILES = main.c parse.c exec.c builtin.c builtin_fcts.c

SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:src/%.c=obj/%.o)

.PHONY: all clean fclean re dirobj

.SILENT: dirobj

all: dirobj $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		$(CC) -o $(NAME) $(OBJ) -L./libft -lft

obj/%.o : src/%.c
		$(CC) $(CFLAGS) -Iinclude -I./libft -o $@ -c $^

clean:
	make clean -C ./libft
	rm -rf obj

fclean: clean
		make fclean -C ./libft
		rm -f $(NAME)

re: fclean all

dirobj:
	mkdir -p obj
