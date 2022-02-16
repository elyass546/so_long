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
	void	*i_p; /*player image*/
	void	*i_g; /*grass image*/
	void	*i_c; /*coin image*/
	void	*i_w; /*wall image*/
	void	*i_ov; /*open vent image*/
	void	*i_cv; /*close vent image*/
	int		coin_c; /*coin counter*/
	int		p_moves; /*player moves*/
	char **s;
}				t_vars;

char	*get_next_line(int fd);
int		move_function(int keycode, t_vars *vars);
char	*ft_strjoin(char *s1, char c);
size_t	ft_strlen(char *str);
void	ft_line_counter(int	*count, char *str);
void	read_map(t_vars *asdf);
void    player_place(t_vars *asdf);;

#endif