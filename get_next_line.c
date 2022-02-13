/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:41:49 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/13 13:07:39 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] > 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char c)
{
    int		i;
    char	*str;

    i = 0;
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*c;
	int		i;
	int		j;

	i = ft_strlen(src);
	j = 0;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	while (src[j])
	{
		c[j] = src[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}

char *get_next_line(int fd)
{
    char    c;
    char    *str;
    char    *temp;
    int     read_return;

    read_return = read(fd, &c, 1);
    str = ft_strdup("");
    while (read_return > 0)
    {
        if (c == '\n')
            break ;
        temp = str;
        str = ft_strjoin(temp, c);
        free (temp);
        read_return = read(fd, &c, 1);
    }
    if (read_return < 0)
    {
        free(str);
        return (NULL);
    }
    if (read_return == 0 && !str)
    {
        free(str);
        return (NULL);
    }
    return (str);
}
