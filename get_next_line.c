/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:41:49 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/11 19:39:10 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *get_next_line(int fd)
{
    char    c;
    char    *str;
    char    *temp;
    int     read_return;

    read_return = read(fd, &c, 1);
    str = malloc(1);
    str[0] = '\0';
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
    if (read_return == 0)
    {
        free(str);
        return (NULL);
    }
    return (str);
}
