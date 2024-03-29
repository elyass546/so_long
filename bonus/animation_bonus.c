/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:55:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 20:16:03 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animation_utiles(t_vars *vars, int i)
{
	if (i < 10)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 75, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m_1, 75, 0);
	}
	else if (i < 20)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 75, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m_2, 75, 0);
	}
	else if (i < 30)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 75, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m_3, 75, 0);
	}
	else if (i < 40)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 75, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m_4, 75, 0);
	}
	else if (i < 50)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 75, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m_5, 75, 0);
	}
}

int	animation(t_vars *vars)
{
	static int	i;

	if (vars->alive == 0)
	{
		if (vars->loop == 100)
		{
			write(1, "Game over !\n", 13);
			exit(1);
		}
		vars->loop++;
	}
	animation_utiles(vars, i);
	if (i == 50)
		i = 0;
	i++;
	return (0);
}
