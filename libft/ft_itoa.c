/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:20:22 by jlopez-c          #+#    #+#             */
/*   Updated: 2019/12/16 13:20:27 by jlopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr)
{
	int			len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -1 * nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

static int	if_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	long	nbr;
	long	len;
	char	*res;

	nbr = (long)n;
	len = int_len(nbr);
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	if (nbr < 0)
		nbr = -1 * nbr;
	while (len >= 0)
	{
		res[len] = (nbr % 10) + '0';
		len--;
		nbr = nbr / 10;
	}
	if (if_negative(n) == 1)
		res[0] = '-';
	return (res);
}
