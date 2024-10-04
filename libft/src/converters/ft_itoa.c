/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:32:46 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:51 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	nbr = ft_abs(n);
	sign = 0;
	len = ft_nbrlen(n);
	str = ft_newstr(len);
	if (!str)
		return (NULL);
	if (n < 0)
		sign = 1;
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
