CC = gcc

CFLAGS = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra

FILES = get_next_line.c line_counter.c\
		map_checker.c player_moves.c\
		read_map.c so_long.c player_moves_utiles.c

NAME = so_long

all : 
	$(CC) $(FLAGS) $(CFLAGS) $(FILES) -o $(NAME)

fclean :
	rm -f $(NAME)
