/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:40:27 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/18 16:46:32 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_line_counter(int	*count, char *s)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror("map name is unacceptable");
		exit(1);
	}
	str = get_next_line(fd);
	count[1] = ft_strlen(str);
	while (str)
	{
		i++;
		free (str);
		str = get_next_line(fd);
	}
	count[0] = i;
}
