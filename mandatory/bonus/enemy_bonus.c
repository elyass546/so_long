/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:20:52 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/25 12:13:53 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy(t_vars *vars)
{
	if (vars->s[vars->enm_y + 1][vars->enm_x] == '0'
		|| vars->s[vars->enm_y + 1][vars->enm_x] == 'P')
	{
		vars->enm_x = vars->enm_i / 75;
		vars->enm_y = vars->enm_j / 75;
		if (vars->switsh == 1)
			enemy_mup(vars);
		else if (vars->switsh == 0)
			enemy_mdown(vars);
	}
	else if (vars->s[vars->enm_y - 1][vars->enm_x] == '0'
		|| vars->s[vars->enm_y - 1][vars->enm_x] == 'P')
	{
		vars->enm_x = vars->enm_i / 75;
		vars->enm_y = vars->enm_j / 75;
		if (vars->switsh1 == 0)
			enemy_mup(vars);
		else if (vars->switsh1 == 1)
			enemy_mdown(vars);
	}
}
