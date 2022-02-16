/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:42:07 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/16 19:21:24 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x + 1] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y][vars->x + 1] == 'C')
	{
		vars->x++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->coin_c--;
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y][vars->x + 1] == 'E' && vars->coin_c == 0)
	{
		vars->x++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
		exit(1);
	}
}

void	left_move(t_vars *vars)
{
	if (vars->s[vars->y][vars->x - 1] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y][vars->x - 1] == 'C')
	{
		vars->x--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->coin_c--;
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y][vars->x - 1] == 'E' && vars->coin_c == 0)
	{
		vars->x--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->i -= 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
		exit(1);
	}
}

void	up_move(t_vars *vars)
{
	if (vars->s[vars->y - 1][vars->x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j -= 75;	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y - 1][vars->x] == 'C')
	{
		vars->y--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j -= 75;	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->coin_c--;
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y - 1][vars->x] == 'E' && vars->coin_c == 0)
	{
		vars->y--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j -= 75;	
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
		exit(1);
	}
}

void	down_move(t_vars *vars)
{
	if (vars->s[vars->y + 1][vars->x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y + 1][vars->x] == 'C')
	{
		vars->y++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->coin_c--;
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
	}
	if (vars->s[vars->y + 1][vars->x] == 'E' && vars->coin_c == 0)
	{
		vars->y++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
		vars->j += 75;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
		vars->s[vars->y][vars->x] = '0';
		vars->p_moves++;
		printf("player moves : %d\n", vars->p_moves);
		exit(1);
	}
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
