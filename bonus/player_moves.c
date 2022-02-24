/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:42:07 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/24 15:04:24 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x + 1] == '0'
		|| vars->s[vars->y][vars->x + 1] == 'P')
		macro_right(vars);
	else if (vars->s[vars->y][vars->x + 1] == 'C')
	{
		macro_right(vars);
		vars->coin_c--;
	}
	else if (vars->s[vars->y][vars->x + 1] == 'I')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		vars->i += 75;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_deadp, vars->i, vars->j);
		vars->alive = 0;
	}
	else if (vars->s[vars->y][vars->x + 1] == 'E' && vars->coin_c == 0)
	{
		macro_right(vars);
		exit(1);
	}
}

void	left_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x - 1] == '0'
		|| vars->s[vars->y][vars->x - 1] == 'P')
		macro_left(vars);
	else if (vars->s[vars->y][vars->x - 1] == 'C')
	{
		macro_left(vars);
		vars->coin_c--;
	}
	else if (vars->s[vars->y][vars->x - 1] == 'I')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		vars->i -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_deadp, vars->i, vars->j);
		vars->alive = 0;
	}
	else if (vars->s[vars->y][vars->x - 1] == 'E' && vars->coin_c == 0)
	{
		macro_left(vars);
		exit(1);
	}
}

void	up_move(t_vars *vars)
{
	if (vars->s[vars->y - 1][vars->x] == '0'
		|| vars->s[vars->y - 1][vars->x] == 'P')
		macro_up(vars);
	else if (vars->s[vars->y - 1][vars->x] == 'C')
	{
		macro_up(vars);
		vars->coin_c--;
	}
	else if (vars->s[vars->y - 1][vars->x] == 'I')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		vars->j -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_deadp, vars->i, vars->j);
		vars->alive = 0;
	}
	else if (vars->s[vars->y - 1][vars->x] == 'E' && vars->coin_c == 0)
	{
		macro_up(vars);
		exit(1);
	}
}

void	down_move(t_vars *vars)
{
	if (vars->s[vars->y + 1][vars->x] == '0'
		|| vars->s[vars->y + 1][vars->x] == 'P')
		macro_down(vars);
	else if (vars->s[vars->y + 1][vars->x] == 'C')
	{
		macro_down(vars);
		vars->coin_c--;
	}
	else if (vars->s[vars->y + 1][vars->x] == 'I')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		vars->j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_g, vars->i, vars->j);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->i_deadp, vars->i, vars->j);
		vars->alive = 0;
	}
	else if (vars->s[vars->y + 1][vars->x] == 'E' && vars->coin_c == 0)
	{
		macro_down(vars);
		exit(1);
	}
}

int	move_function(int keycode, t_vars *vars)
{
	vars->x = vars->i / 75;
	vars->y = vars->j / 75;
	if (vars->alive == 1)
	{
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
	}
	return (0);
}
