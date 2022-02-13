/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:13:00 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/13 21:45:03 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	move_function(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit (1);
	if (keycode == 13)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_bg, vars->height, vars->width);
		vars->width -= 75;	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_p, vars->height, vars->width);
	}
	if (keycode == 0)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_bg, vars->height, vars->width);
		vars->height -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_p, vars->height, vars->width);
	}
	if (keycode == 1)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_bg, vars->height, vars->width);
		vars->width += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_p, vars->height, vars->width);
	}
	if (keycode == 2)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_bg, vars->height, vars->width);
		vars->height += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_p, vars->height, vars->width);
	}
	return (0);
}

void	read_map(t_vars asdf, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			mlx_put_image_to_window(asdf.mlx, asdf.win, asdf.image_bg, asdf.height, asdf.width);
		if (str[i] == '0')
			mlx_put_image_to_window(asdf.mlx, asdf.win, asdf.image_p, asdf.height1, asdf.width1);
		i++;
		asdf.height += 75;
		asdf.height1 += 75;
	}
}


int main()
{
	t_vars	asdf;
	char	*r_path = "amongos.xpm";
	char	*r1_path = "minc.xpm";
	int fd = open("maps", O_RDONLY);
	char *str = get_next_line(fd);
	asdf.mlx = mlx_init();
	asdf.win = mlx_new_window(asdf.mlx, 1000, 700, "so_long");
	asdf.image_p = mlx_xpm_file_to_image(asdf.mlx, r_path, &asdf.height, &asdf.width);
	asdf.image_bg = mlx_xpm_file_to_image(asdf.mlx, r1_path, &asdf.height, &asdf.width);
	asdf.width = 0;
	asdf.height = 0;	
	//mlx_put_image_to_window(asdf.mlx, asdf.win, asdf.image_bg, asdf.height, asdf.width);
	read_map(asdf, str);
	mlx_key_hook(asdf.win, move_function, &asdf);
	mlx_loop(asdf.mlx);
}