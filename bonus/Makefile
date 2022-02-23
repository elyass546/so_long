CC = gcc

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

FILES = get_next_line.c line_counter.c\
		map_checker.c player_moves.c\
		read_map.c so_long.c player_moves_utiles.c\
		ft_putnbr.c itoa.c animation.c enemy.c\
		enemy_utiles.c

NAME = so_long

all : 
	$(CC) $(CFLAGS) $(FLAGS) $(FILES) -o $(NAME)

fclean :
	rm -f $(NAME)
