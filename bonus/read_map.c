/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:39:17 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/24 15:17:41 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_vars *vars, char c, int m, int n)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, m, n);
	else if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, m, n);
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_c, m, n);
		vars->coin_c++;
	}
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_cv, m, n);
}

void	put_coord(t_vars *vars, char c, int m, int n)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, m, n);
		vars->j = n;
		vars->i = m;
	}
	else if (c == 'I')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_enm, m, n);
		vars->enm_i = m;
		vars->enm_j = n;
	}
}

void	read_map2(t_vars *vars, int a, int m, int n)
{
	int	b;

	b = 0;
	while (vars->s[a][b])
	{
		put_coord(vars, vars->s[a][b], m, n);
		if (vars->s[a][b] == 'P')
		{
			vars->y = a;
			vars->x = b;
		}
		else if (vars->s[a][b] == 'I')
		{
			vars->enm_y = a;
			vars->enm_x = b;
		}
		else
			put_images(vars, vars->s[a][b], m, n);
		m += 75;
		b++;
	}
}

void	read_map(t_vars *vars)
{
	int	a;
	int	m;
	int	n;

	m = 0;
	n = 0;
	a = 0;
	while (vars->s[a])
	{
		read_map2(vars, a, m, n);
		m = 0;
		n += 75;
		a++;
	}
}
