/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:42:07 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/15 23:18:16 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x + 1] != '1' && vars->s[vars->y][vars->x + 1] != 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	}
}

void	left_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x - 1] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	}
	if (vars->s[vars->y][vars->x - 1] != 'C')
		vars->coin_c--;
}

void	up_move(t_vars *vars)
{
	if (vars->s[vars->y - 1][vars->x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j -= 75;	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	}
	if (vars->s[vars->y - 1][vars->x] != 'C')
		vars->coin_c--;
}

void	down_move(t_vars *vars)
{
	if (vars->s[vars->y + 1][vars->x] != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	}
	if (vars->s[vars->y + 1][vars->x] != 'C')
		vars->coin_c--;
}

int	move_function(int keycode, t_vars *vars)
{
	vars->x = vars->i / 75;
	vars->y = vars->j / 75;
	if (keycode == 53)
		exit (1);
	if (keycode == 13)
		up_move(vars);
	if (keycode == 0)
		left_move(vars);
	if (keycode == 1)
		down_move(vars);
	if (keycode == 2)
		right_move(vars);
	return (0);
}
