/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/16 19:37:26 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_vars	asdf;
	char	*r_path = "images/amongos.xpm";
	char	*r1_path = "images/minc.xpm";
	char	*r2_path = "images/wall.xpm";
	char	*r3_path = "images/coin.xpm";
	char 	*r4_path = "images/open_vent.xpm";
	char 	*r5_path = "images/closed_vent.xpm";
	int		i = 0;
	int fd = open(av[1], O_RDONLY);
	int		count_line[2];
	
	asdf.mlx = mlx_init();
	if (ac == 2)
		ft_line_counter(count_line, av[1]);
	else
	{
		write(1, "Error\nmap name is Unacceptable", 30);
		exit(1);
	}
	asdf.win = mlx_new_window(asdf.mlx, (count_line[1] * 75), (count_line[0] * 75), "so_long");
	asdf.i_p = mlx_xpm_file_to_image(asdf.mlx, r_path, &asdf.x, &asdf.y);
	asdf.i_g = mlx_xpm_file_to_image(asdf.mlx, r1_path, &asdf.x, &asdf.y);
	asdf.i_w = mlx_xpm_file_to_image(asdf.mlx, r2_path, &asdf.x, &asdf.y);
	asdf.i_c = mlx_xpm_file_to_image(asdf.mlx, r3_path, &asdf.x, &asdf.y);
	asdf.i_ov = mlx_xpm_file_to_image(asdf.mlx, r4_path, &asdf.x, &asdf.y);
	asdf.i_cv = mlx_xpm_file_to_image(asdf.mlx, r5_path, &asdf.x, &asdf.y);

	asdf.s = (char **)malloc(sizeof(char *)*(count_line[0] + 1));
	while (i < count_line[0])
	{
		asdf.s[i] = get_next_line(fd);
		i++;
	}
	asdf.s[i] = NULL;
	read_map(&asdf);
	mlx_key_hook(asdf.win, move_function, &asdf);
	mlx_loop(asdf.mlx);
}