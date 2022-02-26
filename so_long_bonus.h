/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:34:32 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 22:55:06 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*i_deadp;
	void	*i_p_left;
	void	*i_p_right;
	void	*i_g;
	void	*i_c;
	void	*i_w;
	void	*i_cv;
	void	*i_enm;
	void	*m_1;
	void	*m_2;
	void	*m_3;
	void	*m_4;
	void	*m_5;
	int		x;
	int		y;
	int		i;
	int		j;
	int		enm_x;
	int		enm_y;
	int		enm_i;
	int		enm_j;
	int		e_moves;
	int		switsh1;
	int		switsh;
	int		coin_c;
	int		p_moves;
	int		lines_c;
	int		p_c;
	int		c_c;
	int		im_c;
	int		v_c;
	int		size_line;
	int		alive;
	int		loop;
	char	**s;
}				t_vars;

/*******************************************/

typedef struct s_data {
	char	c;
	char	*str;
	char	*temp;
	int		read_return;
}				t_data;

/*******************************************/

size_t	ft_strlen(char *str);

/*******************************************/
int		move_function(int keycode, t_vars *vars);
int		animation(t_vars *vars);

/*******************************************/

char	*ft_strjoin(char *s1, char c);
char	*get_next_line(int fd);

/*******************************************/

void	new_win(t_vars *vars, int weight, int height, int fd);
void	ft_line_counter(int	*count, char *str);
void	player_place(t_vars *asdf);
void	map_checker(t_vars *vars);
void	macro_right(t_vars *vars);
void	enemy_mdown(t_vars *vars);
void	macro_left(t_vars *vars);
void	macro_down(t_vars *vars);
void	enemy_mup(t_vars *vars);
void	read_map(t_vars *asdf);
void	macro_up(t_vars *vars);
void	ft_putstr(char *str);
void	xpm_imgs(t_vars *v);
void	enemy(t_vars *vars);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_itoa(int n);

#endif