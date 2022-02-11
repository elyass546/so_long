/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:25 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/11 19:32:27 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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

	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
