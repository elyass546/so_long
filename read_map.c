/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:39:17 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/15 22:55:36 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		read_map(t_vars *asdf)
{
	int	a;
	int	b;
	int	m = 0;
	int	n = 0;

	a = 0;
	while (asdf->s[a])
	{
		b = 0;
		while (asdf->s[a][b])
		{
			if (asdf->s[a][b] == '0')
				mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_g, m, n);
			if (asdf->s[a][b] == 'P')
			{
				mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_p, m, n);
				asdf->y = a;
				asdf->i = m;
				asdf->x = b;
				asdf->j = n;
			}
			if (asdf->s[a][b] == '1')
				mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_w, m, n);
			if (asdf->s[a][b] == 'C')
			{
				mlx_put_image_to_window(asdf->mlx, asdf->win, asdf->i_c, m, n);
				asdf->coin_c++;
			}
			b++;
			m += 75;
		}
		m = 0;
		n += 75;
		a++;	
	}
	printf("%d\n", asdf->coin_c);
}