/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmah.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:09:06 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:54 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexacon(unsigned long n, char const *base)
{
	int	i;

	i = 0;
	if (n > (ft_strlen(base) - 1))
		i = ft_hexacon(n / ft_strlen(base), base);
	i += ft_printchar(base[n % ft_strlen(base)]);
	return (i);
}

int	ft_printmah(void *format)
{
	unsigned long	n;
	const char		*base;
	int				i;

	n = (unsigned long)format;
	base = "0123456789abcdef";
	i = ft_printstr("0x");
	if (i == -1)
		return (-1);
	i += ft_hexacon(n, base);
	return (i);
}
