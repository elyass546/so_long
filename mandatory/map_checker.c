/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:40:03 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 18:10:31 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(t_vars *vars)
{
	if (vars->p_c < 1 || vars->c_c < 1 || vars->v_c < 1)
	{
		ft_putstr("Error\nmissing one or more ellements.\n");
		exit(1);
	}
	else if (vars->p_c > 1 || vars->v_c > 1)
	{
		ft_putstr("Error\nunnecessary element.\n");
		exit(1);
	}
}

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
			ft_putstr("Error\nwrong line length.\n");
			exit(1);
		}
		i++;
	}
	print_error(vars);
}

void	map_macro(t_vars *vars, int i, int j)
{
	while (vars->s[i][j])
	{
		if (vars->s[0][j] != '1' || vars->s[vars->lines_c - 1][j] != '1')
		{
			ft_putstr("Error\nthere is something wrong in the map lines.\n");
			exit(1);
		}
		else if (vars->s[i][j] == 'P')
			vars->p_c++;
		else if (vars->s[i][j] == 'C')
			vars->c_c++;
		else if (vars->s[i][j] == 'E')
			vars->v_c++;
		else if (vars->s[i][j] != 'E' && vars->s[i][j] != 'C'
					&& vars->s[i][j] != '1')
		{
			if (vars->s[i][j] != 'P' && vars->s[i][j] != '0')
			{
				ft_putstr("Error\nyou add an unacceptable element(s).\n");
				exit(1);
			}
		}
		j++;
	}
}

void	map_checker(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->c_c = 0;
	vars->p_c = 0;
	vars->v_c = 0;
	while (vars->s[i])
	{
		map_macro(vars, i, j);
		i++;
	}
	i = 0;
	while (i < (vars->lines_c))
	{
		vars->size_line = ft_strlen(vars->s[i]) - 1;
		if (vars->s[i][0] != '1' || vars->s[i][vars->size_line] != '1')
		{
			ft_putstr("Error\nsomething wrong in the sidewall line.\n");
			exit(1);
		}
		i++;
	}
	hello(vars);
}
