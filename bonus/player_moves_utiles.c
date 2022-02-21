/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_utiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:02:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/20 20:04:09 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	macro_right(t_vars *vars)
{
	vars->x++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->i += 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = '0';
	ft_putstr("player moves : ");
	ft_putnbr(vars->p_moves);
	ft_putchar('\n');
	vars->p_moves++;
}

void	macro_left(t_vars *vars)
{
	vars->x--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->i -= 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = '0';
	ft_putstr("player moves : ");
	ft_putnbr(vars->p_moves);
	ft_putchar('\n');
	vars->p_moves++;
}

void	macro_up(t_vars *vars)
{
	vars->y--;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->j -= 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = '0';
	ft_putstr("player moves : ");
	ft_putnbr(vars->p_moves);
	ft_putchar('\n');
	vars->p_moves++;
}

void	macro_down(t_vars *vars)
{
	vars->y++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_g, vars->i, vars->j);
	vars->j += 75;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->i_p, vars->i, vars->j);
	vars->s[vars->y][vars->x] = '0';
	ft_putstr("player moves : ");
	ft_putnbr(vars->p_moves);
	ft_putchar('\n');
	vars->p_moves++;
}
