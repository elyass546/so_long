 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:34:32 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 21:18:34 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		i;
	int		j;
	void	*i_p_left;
	void	*i_p_right;
	void	*i_g;
	void	*i_c;
	void	*i_w;
	void	*i_ov;
	void	*i_cv;
	int		coin_c;
	int		p_moves;
	int		lines_c;
	int		p_c;
	int		c_c;
	int		v_c;
	int		size_line;
	char	**s;
}				t_vars;

/*************************************/

typedef struct s_data {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_data;

/*************************************/

size_t	ft_strlen(char *str);

/*************************************/

int		move_function(int keycode, t_vars *vars);

/*************************************/

char	*ft_strjoin(char *s1, char c);
char	*get_next_line(int fd);

/*************************************/

void	ft_line_counter(int	*count, char *str);
void	player_place(t_vars *asdf);
void	map_checker(t_vars *vars);
void	macro_right(t_vars *vars);
void	macro_left(t_vars *vars);
void	macro_down(t_vars *vars);
void	read_map(t_vars *asdf);
void	macro_up(t_vars *vars);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif