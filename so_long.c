/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 22:40:18 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	labas(void)
{
	exit(1);
	return (0);
}

void	xpm_imgs(t_vars *vars)
{
	vars->i_p_left = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/left_side.xpm", &vars->x, &vars->y);
	vars->i_p_right = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/right_side.xpm", &vars->x, &vars->y);
	vars->i_g = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/ground.xpm", &vars->x, &vars->y);
	vars->i_w = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/wall.xpm", &vars->x, &vars->y);
	vars->i_c = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/coin.xpm", &vars->x, &vars->y);
	vars->i_ov = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/open_vent.xpm", &vars->x, &vars->y);
	vars->i_cv = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/closed_vent.xpm", &vars->x, &vars->y);
}

void	new_win(t_vars *vars, int weight, int height, int fd)
{
	int		i;
	char	*file;

	file = "so_long";
	i = 0;
	vars->win = mlx_new_window(vars->mlx, (weight * 75), (height * 75), file);
	xpm_imgs(vars);
	vars->s = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		vars->s[i] = get_next_line(fd);
		i++;
	}
	vars->s[i] = NULL;
}

void	my_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, labas, vars);
	mlx_key_hook(vars->win, move_function, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;
	int		fd;
	int		count_line[2];

	if (ac == 2)
	{
		i = 0;
		vars.coin_c = 0;
		vars.p_moves = 0;
		fd = open(av[1], O_RDONLY);
		vars.mlx = mlx_init();
		ft_line_counter(count_line, av[1]);
		vars.lines_c = count_line[0];
		new_win(&vars, count_line[1], count_line[0], fd);
		map_checker(&vars);
		read_map(&vars);
		my_hooks(&vars);
	}
	else
	{
		ft_putstr("Error\nmissing map name\n");
		exit(1);
	}
}
