/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:02:12 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/26 21:10:07 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	new_win(t_vars *vars, int weight, int height, int fd)
{
	int		i;
	char	*file;

	file = "so_long";
	i = 0;
	vars->win = mlx_new_window(vars->mlx, (weight * 75), (height * 75), file);
	xpm_imgs(vars);
	vars->s = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		vars->s[i] = get_next_line(fd);
		i++;
	}
	vars->s[i] = NULL;
}
