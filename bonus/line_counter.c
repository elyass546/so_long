/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:40:27 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/21 15:41:18 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = &str[ft_strlen(str) - 4];
	s2 = ".ber";
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_line_counter(int	*count, char *s)
{
	int		i;
	int		a;
	char	*str;
	int		fd;

	i = 0;
	a = ft_strcmp(s);
	if (a != 0)
	{
		ft_putstr("Error\nmap name is unacceptable 123");
		exit(1);
	}
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nmap name is unacceptable");
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
