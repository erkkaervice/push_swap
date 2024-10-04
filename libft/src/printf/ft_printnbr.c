/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:50:00 by eala-lah          #+#    #+#             */
/*   Updated: 2024/05/28 12:14:24 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int	i;
	int	j;

	i = ft_nbrlen(n);
	j = 0;
	if (n == INT_MIN)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
		j = ft_printnbr(n / 10);
	if (j == -1)
		return (-1);
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (i);
}
