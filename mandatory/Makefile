CC = gcc

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

FILES = get_next_line.c line_counter.c\
		map_checker.c player_moves.c\
		read_map.c so_long.c player_moves_utiles.c\
		ft_putnbr.c

FILES_BONUS = bonus/get_next_line.c bonus/line_counter_bonus.c\
		bonus/map_checker_bonus.c bonus/player_moves_bonus.c\
		bonus/read_map_bonus.c bonus/so_long_bonus.c bonus/player_moves_utiles_bonus.c\
		bonus/ft_putnbr.c bonus/itoa.c bonus/animation_bonus.c bonus/enemy_bonus.c\
		bonus/enemy_utiles_bonus.c

NAME = so_long

NAME_B = so_long_bonus

all : $(NAME)

$(NAME) : $(FILES)
	$(CC) $(CFLAGS) $(FLAGS) $(FILES) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(FILES_BONUS)
	$(CC) $(CFLAGS) $(FLAGS) $(FILES_BONUS) -o $(NAME_B)

fclean :
	rm -f $(NAME) $(NAME_B)
