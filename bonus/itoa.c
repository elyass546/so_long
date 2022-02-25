/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:36:37 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/02/25 15:46:57 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*nbr_stock(int n, char *sub, int nbr_len)
{
	long int	nb;

	nb = n;
	if (n == 0)
		sub[0] = 48;
	if (n < 0)
	{
		sub[0] = '-';
		nb *= -1;
	}
	while (nbr_len >= 0 && nb > 0)
	{
		sub[nbr_len] = nb % 10 + 48;
		nb /= 10 ;
		nbr_len--;
	}
	return (sub);
}

char	*ft_itoa(int n)
{
	char	*sub;
	int		nbr_len;
	int		nb;

	nb = n;
	nbr_len = 0;
	if (nb < 0)
	{
		nb *= -1;
		nbr_len++;
	}
	if (nb == 0)
		nbr_len = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		nbr_len++;
	}
	sub = (char *)malloc(sizeof(char) * (nbr_len + 1));
	sub[nbr_len + 1] = '\0';
	if (!sub)
		return (NULL);
	nbr_len--;
	nbr_stock(n, sub, nbr_len);
	return (sub);
}
