#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		i;
	int		j;
	void	*i_p;
	void	*i_g;
	void	*i_c;
	void	*i_w;
	int		coin_c; /*coin counter*/
	char **s;
}				t_vars;

char	*get_next_line(int fd);
int		move_function(int keycode, t_vars *vars);
char	*ft_strjoin(char *s1, char c);
size_t	ft_strlen(char *str);
void	ft_line_counter(int	*count);
void	read_map(t_vars *asdf);
void    player_place(t_vars *asdf);;

#endif