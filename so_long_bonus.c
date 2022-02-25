/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/25 16:46:26 by ie-laabb         ###   ########.fr       */
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
	v->i_p = mlx_xpm_file_to_image(v->mlx, "./imgs/player.xpm", &v->x, &v->y);
	v->i_g = mlx_xpm_file_to_image(v->mlx, "./imgs/minc.xpm", &v->x, &v->y);
	v->i_g = mlx_xpm_file_to_image(v->mlx, "./imgs/minc.xpm", &v->x, &v->y);
	v->i_w = mlx_xpm_file_to_image(v->mlx, "./imgs/wall.xpm", &v->x, &v->y);
	v->i_enm = mlx_xpm_file_to_image(v->mlx,
			"./imgs/impstor.xpm", &v->x, &v->y);
	v->i_c = mlx_xpm_file_to_image(v->mlx, "./imgs/coin.xpm", &v->x, &v->y);
	v->i_deadp = mlx_xpm_file_to_image(v->mlx,
			"./imgs/dead_player.xpm", &v->x, &v->y);
	v->i_ov = mlx_xpm_file_to_image(v->mlx,
			"./imgs/open_vent.xpm", &v->x, &v->y);
	v->i_cv = mlx_xpm_file_to_image(v->mlx,
			"./imgs/closed_vent.xpm", &v->x, &v->y);
}

void	new_win(t_vars *vrs, int weight, int height, int fd)
{
	int		i;
	char	*file;

	file = "so_long";
	i = 0;
	vrs->win = mlx_new_window(vrs->mlx, (weight * 75), (height * 75), file);
	xpm_imgs(vrs);
	vrs->s = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		vrs->s[i] = get_next_line(fd);
		i++;
	}
	vrs->s[i] = NULL;
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

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;
	int		fd;
	int		count_line[2];

	i = 0;
	init(&vars);
	fd = open(av[1], O_RDONLY);
	vars.mlx = mlx_init();
	if (ac == 2)
		ft_line_counter(count_line, av[1]);
	else
	{
		write(2, "Error\nmissing map name", 30);
		exit(1);
	}
	vars.lines_c = count_line[0];
	new_win(&vars, count_line[1], count_line[0], fd);
	map_checker(&vars);
	read_map(&vars);
	mlx_hook(vars.win, 17, 0, labas, &vars);
	mlx_key_hook(vars.win, move_function, &vars);
	mlx_loop_hook(vars.mlx, animation, &vars);
	mlx_loop(vars.mlx);
}
