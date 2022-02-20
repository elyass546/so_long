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
	int		lines_c; /*lines counter*/
	int		p_c; /*player counter map_checker*/
	int		c_c; /*coins counter map_checker*/
	int		v_c; /*vent counter map_checker*/
	int		size_line;
	char **s;
}				t_vars;

typedef struct s_data
{
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_data;

typedef struct s_asdf
{
	int p_c;
	int c_c;
	int v_c;
	int size_line;
}				t_asdf;

typedef struct s_map
{
	int	a;
	int	b;
}				t_map;

char	*get_next_line(int fd);
int		move_function(int keycode, t_vars *vars);
char	*ft_strjoin(char *s1, char c);
size_t	ft_strlen(char *str);
void	ft_line_counter(int	*count, char *str);
void	read_map(t_vars *asdf);
void    player_place(t_vars *asdf);
void		map_checker(t_vars *vars);

#endif