CC = gcc

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

FILES = ./mandatory/get_next_line.c\
		./mandatory/line_counter.c\
		./mandatory/map_checker.c \
		./mandatory/player_moves.c\
		./mandatory/read_map.c\
		./mandatory/player_moves_utiles.c\
		./mandatory/ft_putnbr.c\
		so_long.c

FILES_BONUS = ./bonus/get_next_line.c \
				./bonus/line_counter_bonus.c \
				./bonus/map_checker_bonus.c \
				./bonus/player_moves_bonus.c \
				./bonus/read_map_bonus.c \
				./bonus/player_moves_utiles_bonus.c \
				./bonus/ft_putnbr.c \
				./bonus/itoa.c \
				./bonus/animation_bonus.c \
				./bonus/enemy_bonus.c \
				./bonus/enemy_utiles_bonus.c\
				./bonus/new_win.c\
				so_long_bonus.c 

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
