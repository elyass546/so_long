/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/20 18:35:15 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_imgs(t_vars *v)
{
	char	*r1_path;
	char	*r2_path;
	char	*r3_path;
	char	*r4_path;
	char	*r5_path;

	r1_path = "imgs/minc.xpm";
	r2_path = "imgs/wall.xpm";
	r3_path = "imgs/coin.xpm";
	r4_path = "imgs/open_vent.xpm";
	r5_path = "imgs/closed_vent.xpm";
	v->i_p = mlx_xpm_file_to_image(v->mlx, "imgs/player.xpm", &v->x, &v->y);
	v->i_g = mlx_xpm_file_to_image(v->mlx, r1_path, &v->x, &v->y);
	v->i_w = mlx_xpm_file_to_image(v->mlx, r2_path, &v->x, &v->y);
	v->i_c = mlx_xpm_file_to_image(v->mlx, r3_path, &v->x, &v->y);
	v->i_ov = mlx_xpm_file_to_image(v->mlx, r4_path, &v->x, &v->y);
	v->i_cv = mlx_xpm_file_to_image(v->mlx, r5_path, &v->x, &v->y);
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

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;
	int		fd;
	int		count_line[2];

	i = 0;
	vars.coin_c = 0;
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
	mlx_key_hook(vars.win, move_function, &vars);
	mlx_loop(vars.mlx);
}
