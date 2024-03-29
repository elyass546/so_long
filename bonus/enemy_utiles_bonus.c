/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utiles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:17 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/25 20:40:50 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	down_switsh(t_vars *vars)
{
	vars->switsh = 1;
	vars->switsh1 = 0;
}

void	up_switsh(t_vars *vars)
{
	vars->switsh = 0;
	vars->switsh1 = 1;
}

void	enemy_mup(t_vars *vars)
{
	if (vars->s[vars->enm_y - 1][vars->enm_x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		vars->enm_j -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_deadp,
			vars->enm_i, vars->enm_j);
		vars->alive = 0;
	}
	else
	{
		vars->s[vars->enm_y][vars->enm_x] = '0';
		vars->enm_y--;
		vars->s[vars->enm_y][vars->enm_x] = 'I';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		vars->enm_j -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_enm,
			vars->enm_i, vars->enm_j);
		if (vars->s[vars->enm_y - 1][vars->enm_x] == '1'
			|| vars->s[vars->enm_y - 1][vars->enm_x] == 'C')
			up_switsh(vars);
	}
}

void	enemy_mdown(t_vars *vars)
{
	if (vars->s[vars->enm_y + 1][vars->enm_x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		vars->enm_j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_deadp,
			vars->enm_i, vars->enm_j);
		vars->alive = 0;
	}
	else
	{
		vars->s[vars->enm_y][vars->enm_x] = '0';
		vars->enm_y++;
		vars->s[vars->enm_y][vars->enm_x] = 'I';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g,
			vars->enm_i, vars->enm_j);
		vars->enm_j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_enm,
			vars->enm_i, vars->enm_j);
		if (vars->s[vars->enm_y + 1][vars->enm_x] == '1'
			|| vars->s[vars->enm_y + 1][vars->enm_x] == 'C')
			down_switsh(vars);
	}
}
