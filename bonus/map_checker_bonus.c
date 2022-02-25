/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:40:03 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/25 23:23:00 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	hello(t_vars *vars)
{
	int	i;
	int	len_line;
	int	len_line1;

	i = 0;
	len_line = ft_strlen(vars->s[0]);
	while (vars->s[i])
	{
		len_line1 = ft_strlen(vars->s[i]);
		if (len_line1 != len_line)
		{
			write(2, "Error\nwrong line length.", 25);
			exit(1);
		}
		i++;
	}
	if (vars->p_c < 1 || vars->c_c < 1 || vars->v_c < 1 || vars->im_c < 1)
	{
		write(2, "Error\nmissing one or more ellements", 36);
		exit(1);
	}
	else if (vars->p_c > 1 || vars->v_c > 1 || vars->im_c > 1)
	{
		write(2, "Error\nunnecessary element.", 27);
		exit(1);
	}
}

void	map_macro_utils(t_vars *vars, int i, int j)
{
	if (vars->s[i][j] == 'P')
			vars->p_c++;
	else if (vars->s[i][j] == 'C')
		vars->c_c++;
	else if (vars->s[i][j] == 'E')
		vars->v_c++;
	else if (vars->s[i][j] == 'I')
		vars->im_c++;
	else if (vars->s[i][j] != 'E' && vars->s[i][j] != 'C'
				&& vars->s[i][j] != '1')
	{
		if (vars->s[i][j] != 'P' && vars->s[i][j] != '0'
				&& vars->s[i][j] != 'I')
		{
			write(2, "Error\nyou add an unacceptable element(s).", 42);
			exit(1);
		}
	}
}

void	map_macro(t_vars *vars, int i, int j)
{
	while (vars->s[i][j])
	{
		if (vars->s[0][j] != '1' || vars->s[vars->lines_c - 1][j] != '1')
		{
			write(2, "Error\nthere is something wrong in the map lines.", 49);
			exit(1);
		}
		else
			map_macro_utils(vars, i, j);
		j++;
	}
}

void	map_checker(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (vars->s[i])
	{
		map_macro(vars, i, j);
		i++;
	}
	i = 0;
	while (i < vars->lines_c)
	{
		vars->size_line = ft_strlen(vars->s[i]) - 1;
		if (vars->s[i][0] != '1' || vars->s[i][vars->size_line] != '1')
		{
			write(2, "Error\nsomething wrong in the sidewall line.", 55);
			exit(1);
		}
		i++;
	}
	hello(vars);
}
