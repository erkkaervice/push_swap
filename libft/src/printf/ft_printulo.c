/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printulo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:13:35 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:56 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printulo(unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (n > (ft_strlen(base) - 1))
	{
		i = ft_printulo(n / ft_strlen(base));
		if (i == -1)
			return (-1);
	}
	i += ft_printchar(base[n % ft_strlen(base)]);
	if (i == -1)
		return (-1);
	return (i);
}
