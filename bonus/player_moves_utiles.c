/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_utiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:02:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/24 15:19:47 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	macro_right(t_vars *vars)
{
	char	*str;

	vars->x++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->i += 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = 'P';
	vars->s[vars->y][vars->x - 1] = '0';
	vars->p_moves++;
	enemy(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 0);
	str = ft_itoa(vars->p_moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str);
	free(str);
}

void	macro_left(t_vars *vars)
{
	char	*str;

	vars->x--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->i -= 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = 'P';
	vars->s[vars->y][vars->x + 1] = '0';
	vars->p_moves++;
	enemy(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 0);
	str = ft_itoa(vars->p_moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str);
	free(str);
}

void	macro_up(t_vars *vars)
{
	char	*str;

	vars->y--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->j -= 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = 'P';
	vars->s[vars->y + 1][vars->x] = '0';
	vars->p_moves++;
	enemy(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 0);
	str = ft_itoa(vars->p_moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str);
	free(str);
}

void	macro_down(t_vars *vars)
{
	char	*str;

	vars->y++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->j += 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = 'P';
	vars->s[vars->y - 1][vars->x] = '0';
	vars->p_moves++;
	enemy(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 0);
	str = ft_itoa(vars->p_moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str);
	free(str);
}
