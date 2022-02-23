/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:55:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/22 17:44:17 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_vars *vars)
{
    static int  i;

    if (vars->alive == 0)
	{
		if (vars->loop == 15000)
		{
			write(1, "Game over !\n", 13);
			exit(1);
		}
		vars->loop++;
	}
    else if (i < 10)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 75);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->m_1, 0, 75);
    }
    else if (i < 20)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 75);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->m_2, 0, 75);
    }
    else if (i < 30)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 75);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->m_3, 0, 75);
    }
    else if (i < 40)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 75);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->m_4, 0, 75);
    }
    else if (i < 50)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->i_w, 0, 75);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->m_5, 0, 75);
    }
    if (i == 50)
        i = 0;
    i++;
	return (0);
}