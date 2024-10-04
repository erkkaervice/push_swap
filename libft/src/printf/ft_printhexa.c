/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:35:01 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/28 12:10:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long n, char format)
{
	char			*base;
	unsigned int	ui;
	int				i;
	unsigned int	bal;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	ui = (unsigned int)n;
	bal = ft_strlen(base);
	if (ui > (bal - 1))
	{
		i = ft_printhexa(ui / bal, format);
		if (i == -1)
			return (-1);
	}
	i += ft_printchar(base[ui % bal]);
	if (i == -1)
		return (-1);
	return (i);
}
