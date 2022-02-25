/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:39:17 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/24 16:33:30 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_vars *asdf, char c, int m, int n)
{
	if (c == '0')
		mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_g, m, n);
	if (c == '1')
		mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_w, m, n);
	if (c == 'C')
	{
		mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_c, m, n);
		asdf->coin_c++;
	}
	if (c == 'E')
		mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_cv, m, n);
}

void	read_map2(t_vars *asdf, int a, int m, int n)
{
	int	b;

	b = 0;
	while (asdf->s[a][b])
	{
		if (asdf->s[a][b] == 'P')
		{
			mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_p, m, n);
			asdf->y = a;
			asdf->i = m;
			asdf->x = b;
			asdf->j = n;
		}
		else
			put_images(asdf, asdf->s[a][b], m, n);
		b++;
		m += 75;
	}
}

void	read_map(t_vars *asdf)
{
	int	a;
	int	m;
	int	n;

	m = 0;
	n = 0;
	a = 0;
	while (asdf->s[a])
	{
		read_map2(asdf, a, m, n);
		m = 0;
		n += 75;
		a++;
	}
}
