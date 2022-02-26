/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 23:12:14 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	labas(void)
{
	exit(1);
	return (0);
}

void	xpm_imgs(t_vars *v)
{
	v->m_1 = mlx_xpm_file_to_image(v->mlx, "./imgs/move1.xpm", &v->x, &v->y);
	v->m_2 = mlx_xpm_file_to_image(v->mlx, "./imgs/move2.xpm", &v->x, &v->y);
	v->m_3 = mlx_xpm_file_to_image(v->mlx, "./imgs/move3.xpm", &v->x, &v->y);
	v->m_4 = mlx_xpm_file_to_image(v->mlx, "./imgs/move4.xpm", &v->x, &v->y);
	v->m_5 = mlx_xpm_file_to_image(v->mlx, "./imgs/move5.xpm", &v->x, &v->y);
	v->i_p_left = mlx_xpm_file_to_image(v->mlx, "./imgs/left_side.xpm", &v->x, &v->y);
	v->i_p_right = mlx_xpm_file_to_image(v->mlx, "./imgs/right_side.xpm", &v->x, &v->y);
	v->i_g = mlx_xpm_file_to_image(v->mlx, "./imgs/ground.xpm", &v->x, &v->y);
	v->i_w = mlx_xpm_file_to_image(v->mlx, "./imgs/wall.xpm", &v->x, &v->y);
	v->i_enm = mlx_xpm_file_to_image(v->mlx,
			"./imgs/final_imposter.xpm", &v->x, &v->y);
	v->i_c = mlx_xpm_file_to_image(v->mlx, "./imgs/coin.xpm", &v->x, &v->y);
	v->i_deadp = mlx_xpm_file_to_image(v->mlx,
			"./imgs/dead_player.xpm", &v->x, &v->y);
	v->i_cv = mlx_xpm_file_to_image(v->mlx,
			"./imgs/closed_vent.xpm", &v->x, &v->y);
}

void	init(t_vars *vars)
{
	vars->coin_c = 0;
	vars->alive = 1;
	vars->loop = 0;
	vars->p_moves = 0;
	vars->switsh = 0;
	vars->switsh1 = 0;
	vars->c_c = 0;
	vars->p_c = 0;
	vars->v_c = 0;
	vars->im_c = 0;
}

void	my_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, labas, vars);
	mlx_key_hook(vars->win, move_function, vars);
	mlx_loop_hook(vars->mlx, animation, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;
	int		fd;
	int		count_line[2];

	i = 0;
	if (ac == 2)
	{
		init(&vars);
		fd = open(av[1], O_RDONLY);
		ft_line_counter(count_line, av[1]);
		vars.lines_c = count_line[0];
		vars.mlx = mlx_init();
		new_win(&vars, count_line[1], count_line[0], fd);
		map_checker(&vars);
		read_map(&vars);
		my_hooks(&vars);
	}
	else
	{
		write(2, "Error\nmissing map name", 30);
		exit(1);
	}
}
